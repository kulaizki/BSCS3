const express = require('express');
const router = express.Router();
const { register, login, profile } = require('../controllers/userController');
const { authMiddleware, limiter } = require('../middleware/authMiddleware'); 

router.post('/register', register);
router.post('/login', login);
router.get('/profile', limiter, authMiddleware, profile); 

module.exports = router;
