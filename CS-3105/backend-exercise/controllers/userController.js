const { getUsers, saveUsers } = require('../models/userModel');
const Joi = require('joi');
const jwt = require('jsonwebtoken');

// Registration controller
const register = (req, res) => {
  const schema = Joi.object({
    username: Joi.string().min(3).required(),
    password: Joi.string().min(5).required(),
    email: Joi.string().email().required(),
  });

  const { error } = schema.validate(req.body);
  if (error) return res.status(400).json({ message: error.details[0].message });

  const { username, password, email } = req.body;
  const users = getUsers(); // Read users from file

  const userExists = users.find((u) => u.username === username);
  if (userExists) return res.status(400).json({ message: 'User already exists' });

  const newUser = { id: users.length + 1, username, password, email };
  users.push(newUser);

  saveUsers(users); // Save the updated users back to the file

  res.status(201).json({ message: 'User registered successfully' });
};

// Login controller
const login = (req, res) => {
  const { username, password } = req.body;
  const users = getUsers(); // Read users from file

  const user = users.find((u) => u.username === username && u.password === password);
  if (!user) return res.status(400).json({ message: 'Invalid credentials' });

  const token = jwt.sign({ id: user.id }, 'secret_key', { expiresIn: '1h' });
  res.json({ message: 'Logged in successfully', token });
};

// Profile controller
const profile = (req, res) => {
  const users = getUsers(); // Read users from file
  const user = users.find((u) => u.id === req.user.id);
  if (!user) return res.status(404).json({ message: 'User not found' });

  res.json({ user });
};

module.exports = { register, login, profile };
