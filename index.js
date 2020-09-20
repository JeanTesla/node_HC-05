
const express = require("express");
const app = express();

const http = require('http').createServer(app)
const io = require('socket.io')(http)
http.listen(4000, () => {
    console.log('[ Socket iniciado na porta 4000 ]')
})

const Readline = require('@serialport/parser-readline')
var SerialPort = require("serialport");
var serialport = new SerialPort("/dev/rfcomm0", { baudRate: 9600 });
const parser = new Readline()
serialport.pipe(parser)
serialport.on("open", function () {
    console.log('Serial Port conectada')
});



io.on('connection', socket => {
    console.log('Alguém conectou!')
    socket.on('frente', () => {
        console.log('ᐃ')
        serialport.write('A')      
    })
    socket.on('tras', () => {
        console.log('ᐁ')
        serialport.write('E')
    })
    socket.on('esquerda', () => {
        console.log('ᐊ')
        serialport.write('C')
    })
    socket.on('direita', () => {
        console.log('ᐅ')
        serialport.write('B')
    })
    socket.on('velDown', () => {
        console.log('- velocidade')
        serialport.write('Y')
    })
    socket.on('velUp', () => {
        console.log('+ velocidade')
        serialport.write('Z')
    })
    socket.on('pararDirecao', () => {
        serialport.write('J')
    })
    socket.on('pararMovimento', () => {
        serialport.write('K')
    })
    socket.on('sensibilidade1', () => {
        serialport.write('1')
    })
    socket.on('sensibilidade2', () => {
        serialport.write('2')
    })
    socket.on('sensibilidade3', () => {
        serialport.write('3')
    })
    socket.on('piscar', () => {
        serialport.write('L')
    })
    serialport.on('data', data => {
        let dado = data.toString()
        socket.emit('marcha', dado)
    })


    


    socket.on('disconnect', () => {
        console.log(`${socket.id} desconectou.`)
    })
})

