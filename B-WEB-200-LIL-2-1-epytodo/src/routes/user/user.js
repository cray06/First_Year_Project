const express = require('express');
const bcrypt = require('bcryptjs');
const jwt = require('jsonwebtoken');
const auth = require('../../middleware/auth');
const {
    getUserByIdOrEmail,
    getAllUserInfo,
    getUserTodos,
    updateUser,
    deleteUser,
    registerUser,
    loginUser
} = require('./user.query');
const router = express.Router();

router.post('/register', async (req, res) => {
    try {
        const { email, name, firstname, password } = req.body;
        if (!email || !name || !firstname || !password) {
            return res.status(400).json({ msg: 'Bad parameter' });
        }
        const [[existing]] = await pool.query('SELECT id FROM user WHERE email = ?', [email]);
        if (existing) {
            return res.status(409).json({ msg: 'Account already exists' });
        }
        const token = await registerUser({ email, name, firstname, password });
        res.status(201).json({ token });
    } catch (err) {
        res.status(500).json({ msg: 'Internal server error' });
    }
});

router.post('/login', async (req, res) => {
    try {
        const { email, password } = req.body;
        if (!email || !password) {
            return res.status(400).json({ msg: 'Bad parameter' });
        }
        const [[user]] = await pool.query('SELECT * FROM user WHERE email = ?', [email]);
        if (!user) {
            return res.status(401).json({ msg: 'Invalid Credentials' });
        }
        const match = await bcrypt.compare(password, user.password);
        if (!match) {
            return res.status(401).json({ msg: 'Invalid Credentials' });
        }
        const token = await loginUser({ email, password });
        res.status(200).json({ token });
    } catch (err) {
        res.status(500).json({ msg: 'Internal server error' });
    }
});

router.get('/user', auth, async (req, res) => {
    const token = req.headers.authorization;
    if (!token) {
        return res.status(401).json({ msg: 'No Token, authorization denied' });
    }
    try {
        const user = await getAllUserInfo(req.user.id);
        if (!user) {
            return res.status(404).json({ msg: 'Not found' });
        }
        res.status(200).json(user);
    } catch (err) {
        res.status(500).json({ msg: 'Internal server error' });
    }
});

router.get('/user/todos', auth, async (req, res) => {
    const token = req.headers.authorization;
    if (!token) {
        return res.status(401).json({ msg: 'No Token, authorization denied' });
    }
    try {
        const todos = await getUserTodos(req.user.id);
        res.status(200).json(todos);
    } catch (err) {
        res.status(500).json({ msg: 'Internal server error' });
    }
});

router.get('/users/:id', auth, async (req, res) => {
    try {
        const user = await getUserByIdOrEmail(req.params.id);

        if (!user) {
            return res.status(404).json({ msg: 'Not found' });
        }

        res.status(200).json(user);
    } catch (err) {
        res.status(500).json({ msg: 'Internal server error' });
    }
});

router.put('/users/:id', auth, async (req, res) => {
    try {
        const updatedUser = await updateUser(req.params.id, req.body);

        if (!updatedUser) {
            return res.status(404).json({ msg: 'Not found' });
        }

        res.status(200).json(updatedUser);
    } catch (err) {
        res.status(500).json({ msg: 'Internal server error' });
    }
});

router.delete('/users/:id', auth, async (req, res) => {
    try {
        const message = await deleteUser(req.params.id);

        if (!message) {
            return res.status(404).json({ msg: 'Not found' });
        }

        res.status(200).json({ msg: message });
    } catch (err) {
        res.status(500).json({ msg: 'Internal server error' });
    }
});

module.exports = router;
