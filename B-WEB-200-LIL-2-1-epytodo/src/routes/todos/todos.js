const express = require('express');
const auth = require('../../middleware/auth');
const {
    getTodos,
    getTodoById,
    createTodo,
    updateTodo,
    deleteTodo
} = require('./todos.query');

const router = express.Router();

router.get('/', auth, async (req, res) => {
    try {
        const todos = await getTodos();
        res.status(200).json(todos);
    } catch (err) {
        res.status(500).json({ msg: 'Internal server error' });
    }
});


router.get('/:id', auth, async (req, res) => {
    try {
        const todo = await getTodoById(req.params.id);
        
        if (parseInt(req.params.id) !== todo.user_id) {
            return res.status(400).json({ msg: 'Bad parameter' });
        }
        if (!todo)
            return res.status(404).json({ msg: 'Not found' });
        res.status(200).json(todo);
    } catch (err) {
        res.status(500).json({ msg: 'Internal server error' });
    }
});

router.post('/', auth, async (req, res) => {
    try {
        const { title, description, due_time, status } = req.body;
        if (!title || !description || !due_time || !status) {
            return res.status(400).json({ msg: 'Bad parameter' });
        }
        const todo = await createTodo(req.user.id, { title, description, due_time, status });
        if (todo.error) {
            return res.status(400).json({ msg: 'Bad parameter' });
        }
        res.status(201).json(todo);
    } catch (err) {
        res.status(500).json({ msg: 'Internal server error' });
    }
});

router.put('/:id', auth, async (req, res) => {
    try {
        const updated = await updateTodo(req.user.id, req.params.id, req.body);
        if (updated.error) {
            if (updated.error === 'Bad parameter') {
                return res.status(400).json({ msg: updated.error });
            }
            if (updated.error === 'Not found') {
                return res.status(404).json({ msg: updated.error });
            }
            return res.status(500).json({ msg: updated.error });
        }
        res.status(200).json(updated);
    } catch (err) {
        res.status(500).json({ msg: 'Internal server error' });
    }
});

router.delete('/:id', auth, async (req, res) => {
    try {
        const msg = await deleteTodo(req.user.id, req.params.id);
        if (msg.error) {
            return res.status(404).json({ msg: 'Not found' });
        }
        res.status(200).json({ msg: msg });
    } catch (err) {
        res.status(500).json({ msg: 'Internal server error' });
    }
});

module.exports = router;