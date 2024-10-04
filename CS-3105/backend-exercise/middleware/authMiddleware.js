const jwt = require('jsonwebtoken');
const rateLimit = require('express-rate-limit');

// Define the rate limiting rule
const limiter = rateLimit({
  windowMs: 30 * 1000, // 30 seconds
  max: 5, // Limit each IP to 5 requests per windowMs
  message: 'Too many requests from this IP, please try again after 30 seconds.',
});

const authMiddleware = (req, res, next) => {
  const token = req.header('Authorization');
  if (!token) return res.status(401).json({ message: 'Access denied. No token provided.' });

  try {
    const cleanToken = token.replace('Bearer ', '');
    const decoded = jwt.verify(cleanToken, 'secret_key');
    req.user = decoded;
    next();
  } catch (err) {
    res.status(400).json({ message: 'Invalid token' });
  }
};

module.exports = { authMiddleware, limiter };
