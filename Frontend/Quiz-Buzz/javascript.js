(function(){

    var data = {
        quizContent: [
            {
                question: "What is the full meaning of CPU?",
                answer1: "Computer Processing Unit",
                answer2: "Computing Process Unit",
                answer3: "Center Processing Unit",
                answer4: "Central Processing Unit",
                answer5: "Central Power Unit",
                correctAnswer: 4
            },
            {
                question: "Which of these an application software?",
                answer1: "CPU",
                answer2: "Ms word",
                answer3: "Windows",
                answer4: "Android",
                answer5: "Ios",
                correctAnswer: 2
            },
            {
                question: "One of these is backend programming language?",
                answer1: "Ms word",
                answer2: "Vanila Js",
                answer3: "Angula",
                answer4: "Ruby",
                answer5: "JavaScript",
                correctAnswer: 4
            },
            {
                question: "All but one, is not a frontend Language:",
                answer1: "Python",
                answer2: "c#",
                answer3: "HTML/CSS",
                answer4: "NodeJs",
                answer5: "PHP",
                correctAnswer: 3
            },
            {
                question: "What is the full meaning of DOM?",
                answer1: "Data order model",
                answer2: "Document Object Model",
                answer3: "Document Oblect Method",
                answer4: "data Object method",
                answer5: "Data Object Model",
                correctAnswer: 2
            }
        ],
        points: 0
    };
    
    var display = {
        getApp: document.getElementById('app'),
  
        // Updates DOM on start/restart of the quiz
        mainPage: function() {
            var newEl = '<div class="quest-number"><p id="questNumber"></p></div><h1 id="questionDisplay" class="h3"></h1>';
                newEl += '<ul><li><label><input type="radio" name="answers" id="input1" value="1"><span class="outer"><span class="inner"></span></span><div id="answerDisplay1"></div></label></li>';
                newEl += '<li><label><input type="radio" name="answers" id="input2" value="2"><span class="outer"><span class="inner"></span></span><div id="answerDisplay2"></div></label></li>';
                newEl += '<li><label><input type="radio" name="answers" id="input3" value="3"><span class="outer"><span class="inner"></span></span><div id="answerDisplay3"></div></label></li>';
                newEl += '<li><label><input type="radio" name="answers" id="input4" value="4"><span class="outer"><span class="inner"></span></span><div id="answerDisplay4"></div></label></li>';
                newEl += '<li><label><input type="radio" name="answers" id="input5" value="5"><span class="outer"><span class="inner"></span></span><div id="answerDisplay5"></div></label></li></ul>';
                newEl += '<div class="points-wrap"><p id="currentPoints"></p></div>';
  
            this.getApp.innerHTML = newEl;
        },
  
        // Updates DOM with each question
        updateMainPage: function() {
            var getQuestNumber = document.getElementById('questNumber'),
                getQuestion = document.getElementById('questionDisplay'),
                getAnswer1 = document.getElementById('answerDisplay1'),
                getAnswer2 = document.getElementById('answerDisplay2'),
                getAnswer3 = document.getElementById('answerDisplay3'),
                getAnswer4 = document.getElementById('answerDisplay4'),
                getAnswer5 = document.getElementById('answerDisplay5'),
                getCurrentPoints = document.getElementById('currentPoints'),
                sumOfQuestions = data.quizContent.length;
                
            getQuestNumber.innerHTML = control.count + 1 + '/' + sumOfQuestions;
            getQuestion.innerHTML = data.quizContent[control.count].question;
            getAnswer1.innerHTML = data.quizContent[control.count].answer1;
            getAnswer2.innerHTML = data.quizContent[control.count].answer2;
            getAnswer3.innerHTML = data.quizContent[control.count].answer3;
            getAnswer4.innerHTML = data.quizContent[control.count].answer4;
            getAnswer5.innerHTML = data.quizContent[control.count].answer5;
            getCurrentPoints.innerHTML = 'Points:' + ' ' + data.points;
            this.newElement('button', 'submit', 'Submit Answer');
        },
        addAnswer: function(showMessage) {
            var sumOfQuestions = data.quizContent.length;
  
            if(showMessage === 'correct') {
                this.newElement('p', 'showAnswer', 'Correct Answer!')/*.style.backgoundColor='green'*/;
            } else {
                this.newElement('p', 'showAnswer', 'Incorrect Answer!')/*.style.backgroundColor='red'*/;
            }
  
            if (control.count < sumOfQuestions - 1) {
                this.newElement('button', 'nextQuest', 'Next question');
            } else {
                this.newElement('button', 'result', 'See your result');
            }
        },
        removeAnswer: function(event) {
            var getShowAnswer = document.getElementById('showAnswer');
            var getShowAnswerParent = getShowAnswer.parentNode;
            getShowAnswerParent.removeChild(getShowAnswer);
            var clickedEl = event.target;
            var clickedElParent = clickedEl.parentNode;
            clickedElParent.removeChild(clickedEl);
            var radioButtons = document.getElementsByName('answers');
            var allRadioButtons = radioButtons.length;
            var i;
  
            for(i = 0; i < allRadioButtons; i++) {
                radioButtons[i].checked = false;
            }
        },
  
        backgoundColor: function correctAnswer(){
          if(radioButtons[i].checked === correctAnswer){
            document.getElementsByName('answers').style.backgoundColor ='green';
          }else if(radioButtons[i].checked !== correctAnswer){
            document.getElementsByName('answer').style.backgoundColor = 'red';
          }
          //correctAnswer();
        },
        
        
          
  
        
        // Displays final page of the quiz
        resultPage: function() {
            this.getApp.innerHTML = '<h1 class="h3">You have ' + data.points + ' question(s) of 5, answered correctly</h1>';
            this.newElement('button', 'restart', 'Restart Quiz');
        },
        newElement: function(elem, elemId, elemText) {
            var newElem = document.createElement(elem);
            var newElemText = document.createTextNode(elemText);
            newElem.appendChild(newElemText);
            newElem.id = elemId;
            this.getApp.appendChild(newElem);
        }
    };
  
    var control = {
        init: function() {
            var start = document.getElementById('start') || document.getElementById('restart');
            start.addEventListener('click', function() {
                display.mainPage();
                control.update();
            }, false);
        },
        update: function() {
            display.updateMainPage();
            var submit = document.getElementById('submit');
            submit.addEventListener('click', this.checkAnswer, false);
        },
  
  
        /**
        * Alerts if none of the radios is checked on submit 
        * Verifies correct/incorrect answer
        * Directs quiz to the next question or to the final page
        */
       
      
  
        checkAnswer: function(event) {
            var radioButtons = document.getElementsByName('answers'),
                allRadioButtons = radioButtons.length,
                isChecked = false,
                checkedRadio,
                clickedEl = event.target,
                clickedElParent = clickedEl.parentNode,
                i;
  
            for (i = 0; i < allRadioButtons; i++) {
                if (radioButtons[i].checked) {
                    isChecked = true;
                    checkedRadio = +radioButtons[i].value;
                }
            }
  
            if (isChecked === false) {
                alert('Please choose the answer!');
            } else {
                clickedElParent.removeChild(clickedEl);
                if (checkedRadio === data.quizContent[control.count].correctAnswer) {
                    display.addAnswer('correct');
                    data.points++;
                } else {
                    display.addAnswer();
                }
  
                var nextQuestion = document.getElementById('nextQuest'),
                    result = document.getElementById('result');
  
                if (nextQuestion) {
                    nextQuestion.addEventListener('click', function(event) {
                        control.count++;
                        display.removeAnswer(event);
                        control.update();
                    }, false);
                } else {
                    result.addEventListener('click', function() {
                        display.resultPage();
                        control.init();
                        control.count = 0;
                        data.points = 0;
                    }, false);
                }
            }
        },
  
    
      
      // answer is Wrong
      /*function wrongAnswer(){
        (checkedRadio !== data.quizContent[control.count].correctAnswer){
          document.getElementById('input').style.backgroundColor = "#0f0";
  
        }
     
     
     
  }
      
     /* {
          document.getElementById(runningQuestion).style.backgroundColor = "#f00";
      }*/
      
  
        // Used for incrementing/looping through the quiz questions and answers
        count: 0
    };
  
    control.init();
  
  
  })();