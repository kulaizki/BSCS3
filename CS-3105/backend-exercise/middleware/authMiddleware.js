const jwt = require('jsonwebtoken');

const authMiddleware = (req, res, next) => {
  const token = req.header('Authorization'); // Get the Authorization header
  if (!token) return res.status(401).json({ message: 'Access denied. No token provided.' });

  try {
    const cleanToken = token.replace('Bearer ', ''); // Remove "Bearer " from the token
    const decoded = jwt.verify(cleanToken, 'secret_key'); // Verify the token using the secret key
    req.user = decoded; // Attach decoded user information to the request object
    next(); // Move to the next middleware or route handler
  } catch (err) {
    res.status(400).json({ message: 'Invalid token' });
  }
};

module.exports = authMiddleware;
