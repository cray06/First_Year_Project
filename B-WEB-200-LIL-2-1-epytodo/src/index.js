const express = require('express');
const app = express();
require('dotenv').config();
const authRoutes = require('./routes/auth/auth');
const userRoutes = require('./routes/user/user');
const todoRoutes = require('./routes/todos/todos');
const { notFound } = require('./middleware/notFound');

app.use(express.json());
app.use('/', authRoutes);
app.use('/', userRoutes);
app.use('/todos', todoRoutes);
app.use(notFound);

app.listen(process.env.PORT, () => {
  console.log(`Server running on port ${process.env.PORT}`);
});