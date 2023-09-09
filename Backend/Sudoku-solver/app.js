
const puzzleBoard = document.querySelector('#puzzle');
const solveButton = document.querySelector('#solve-button');
const sqaure = 81;
const submission = [];
// we need 81 sqaure 9*9 grid

for(let i=0; i<sqaure; i++){
    const inputElement = document.createElement('input'); // we will use input as a string
    inputElement.setAttribute('type', 'number');
    inputElement.setAttribute('min', 1);
    inputElement.setAttribute('max', 9);
    puzzleBoard.appendChild(inputElement);
}

// for joining values in an array

const joinValues = () => {
    const inputs = document.querySelectorAll('input');
    inputs.forEach(input => {
        if(input.value){
            submission.push(input.value);
        }else{
            submission.push('.');
        }
    })

    console.log(submission);
}

// calling API
const solve= async ()=>{
    // const axios = require('axios');

    const options = {
    method: 'POST',
    url: 'https://sudoku-solver3.p.rapidapi.com/sudokusolver/',
    headers: {
        'content-type': 'application/json',
        'X-RapidAPI-Key': '184b1e331bmsh2344fa87eb23102p1939f4jsn622dea5d430f',
        'X-RapidAPI-Host': 'sudoku-solver3.p.rapidapi.com'
    },
    data: {
        input: [
        0,
        0,
        8,
        9,
        0,
        0,
        4,
        0,
        0,
        0,
        0,
        5,
        6,
        0,
        0,
        0,
        0,
        0,
        3,
        0,
        0,
        7,
        0,
        0,
        6,
        0,
        9,
        5,
        0,
        0,
        0,
        0,
        4,
        0,
        2,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        6,
        5,
        0,
        0,
        2,
        0,
        0,
        1,
        3,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        3,
        0,
        0,
        8,
        9,
        0,
        0,
        0,
        7,
        0,
        4,
        0,
        0,
        2,
        0,
        0
        ]
    }
    };

    try {
        const response = await axios.request(options);
        console.log(response.data);
    } catch (error) {
        console.error(error);
    }
}



// callback function: joinValues
solveButton.addEventListener('click', solve)