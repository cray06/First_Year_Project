const express = require('express');
const router = express.Router();
const db = require('../../config/db');
const bcrypt = require('bcryptjs');
const jwt = require('jsonwebtoken');
require('dotenv').config();

router.post('/register', async (req, res) => {
  const { email, password, name, firstname } = req.body;

  if (!email || !password || !name || !firstname) {
    return res.status(400).json({ msg: 'Bad parameter' });
  }

  try {
    const [[user]] = await db.query('SELECT * FROM user WHERE email = ?', [email]);
    if (user)
      return res.status(409).json({ msg: 'Account already exists' });

    const hash = await bcrypt.hash(password, 10);
    const [result] = await db.query(
      'INSERT INTO user (email, password, name, firstname) VALUES (?, ?, ?, ?)',
      [email, hash, name, firstname]
    );

    const token = jwt.sign({ user: { id: result.insertId } }, process.env.SECRET);
    res.status(201).json({ token });
  } catch (err) {
    res.status(500).json({ msg: 'Internal server error' });
  }
});

router.post('/login', async (req, res) => {
  const { email, password } = req.body;
  if (!email || !password) {
    return res.status(400).json({ msg: 'Bad parameter' });
  }

  try {
    const [[user]] = await db.query('SELECT * FROM user WHERE email = ?', [email]);
    if (!user || !(await bcrypt.compare(password, user.password))) {
      return res.status(401).json({ msg: 'Invalid Credentials' });
    }

    const token = jwt.sign({ user: { id: user.id } }, process.env.SECRET);
    res.status(201).json({ token });
  } catch (err) {
    res.status(500).json({ msg: 'Internal server error' });
  }
});

module.exports = router;
