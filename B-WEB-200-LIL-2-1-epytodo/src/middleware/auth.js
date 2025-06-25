const jwt = require('jsonwebtoken');
require('dotenv').config();

function auth(req, res, next) {
    const authHeader = req.header('Authorization');

    if (!authHeader)
        return res.status(401).json({ msg: "No token, authorization denied" });

    let token;
    
    if (authHeader.startsWith('Bearer '))
        token = authHeader.substring(7);
    else
        token = authHeader;

    try {
        const decoded = jwt.verify(token, process.env.SECRET);
        req.user = decoded.user;
        next();
    } catch (err) {
        res.status(401).json({ msg: "Token is not valid" });
    }
}

module.exports = auth;
