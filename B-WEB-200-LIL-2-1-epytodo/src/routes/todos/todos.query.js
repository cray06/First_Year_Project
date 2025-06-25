const pool = require('../../config/db');

function formatDate(dateString) {
    const date = new Date(dateString);
    const year = date.getFullYear();
    const month = String(date.getMonth() + 1).padStart(2, '0');
    const day = String(date.getDate()).padStart(2, '0');
    const hours = String(date.getHours()).padStart(2, '0');
    const minutes = String(date.getMinutes()).padStart(2, '0');
    const seconds = String(date.getSeconds()).padStart(2, '0');
    return `${year}/${month}/${day} ${hours}:${minutes}:${seconds}`;
}

async function getTodos() {
    const [todos] = await pool.query('SELECT * FROM todo');
    return todos;
}

async function getTodoById(todoId) {
    const [[todo]] = await pool.query('SELECT * FROM todo WHERE id = ?', [todoId]);
    return todo;
}

async function createTodo(userId, { title, description, due_time, status }) {
    if (!title || !description || !due_time || !status) {
        return { error: 'Bad parameter' };
    }

    const formattedDate = formatDate(due_time);
    const [result] = await pool.query(
        `INSERT INTO todo (title, description, due_time, status, user_id)
         VALUES (?, ?, ?, ?, ?)`,
        [title, description, formattedDate, status, userId]
    );

    return getTodoById(userId, result.insertId);
}

async function updateTodo(userId, todoId, { title, description, due_time, status }) {
    if (!title || !description || !due_time || !status) {
        return { error: 'Bad parameter' };
    }

    const [existing] = await pool.query('SELECT * FROM todo WHERE id = ? AND user_id = ?', [todoId, userId]);
    
    if (existing.length === 0) {
        return { error: 'Not found' };
    }

    const formattedDate = formatDate(due_time);
    await pool.query(
        `UPDATE todo SET title = ?, description = ?, due_time = ?, status = ? WHERE id = ? AND user_id = ?`,
        [title, description, formattedDate, status, todoId, userId]
    );

    return getTodoById(userId, todoId);
}

async function deleteTodo(userId, todoId) {
    const [result] = await pool.query('DELETE FROM todo WHERE id = ? AND user_id = ?', [todoId, userId]);

    if (result.affectedRows === 0) {
        throw new Error('Not found');
    }

    return { message: `Successfully deleted record number: ${todoId}` };
}

module.exports = {
    getTodos,
    getTodoById,
    createTodo,
    updateTodo,
    deleteTodo
};
