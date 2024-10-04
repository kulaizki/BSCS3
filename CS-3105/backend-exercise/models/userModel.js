const fs = require('fs');
const path = require('path');
const usersFilePath = path.join(__dirname, '../data/users.json');

// read users from JSON file
const getUsers = () => {
  try {
    const usersData = fs.readFileSync(usersFilePath, 'utf8');
    return JSON.parse(usersData);
  } catch (error) {
    console.error('Error reading users from file:', error);
    return []; // Return an empty array if there's an error
  }
};

// write users to JSON file
const saveUsers = (users) => {
  try {
    fs.writeFileSync(usersFilePath, JSON.stringify(users, null, 2), 'utf8');
  } catch (error) {
    console.error('Error writing users to file:', error);
  }
};

module.exports = { getUsers, saveUsers };
