const pool = require('../../config/db');
const bcrypt = require('bcryptjs');
const jwt = require('jsonwebtoken');
require('dotenv').config();

async function registerUser({ email, name, firstname, password }) {
    const hash = await bcrypt.hash(password, 10);
    const [result] = await pool.query(
        'INSERT INTO user (email, name, firstname, password) VALUES (?, ?, ?, ?)',
        [email, name, firstname, hash]
    );
    
    const token = jwt.sign({ user: { id: result.insertId } }, process.env.SECRET);
    return token;
}

async function loginUser({ email, password }) {
    const token = jwt.sign({ user: { id: user.id } }, process.env.SECRET);
    return token;
}

async function getAllUserInfo(userId) {
    const [[user]] = await pool.query('SELECT * FROM user WHERE id = ?', [userId]);
    return user;
}

async function getUserTodos(userId) {
    const [todos] = await pool.query('SELECT * FROM todo WHERE user_id = ?', [userId]);
    return todos;
}

async function getUserByIdOrEmail(value) {
    let key;

    if (parseInt(value).toString() === value.toString()) {
        key = 'id';
    } else {
        key = 'email';
    }

    const [[user]] = await pool.query(`SELECT * FROM user WHERE ${key} = ?`, [value]);
    return user;
}

async function updateUser(id, { email, password, firstname, name }) {
    if (!email || !password || !firstname || !name) {
        return null;
    }

    const hash = await bcrypt.hash(password, 10);

    await pool.query(
        'UPDATE user SET email = ?, password = ?, firstname = ?, name = ? WHERE id = ?',
        [email, hash, firstname, name, id]
    );

    const user = await getUserByIdOrEmail(id);
    return user;
}

async function deleteUser(id) {
    const [result] = await pool.query('DELETE FROM user WHERE id = ?', [id]);

    if (result.affectedRows === 0) {
        return null;
    }

    return `Successfully deleted record number : ${id}`;
}

module.exports = {
    registerUser,
    loginUser,
    getAllUserInfo,
    getUserTodos,
    getUserByIdOrEmail,
    updateUser,
    deleteUser
};
