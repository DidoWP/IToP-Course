/**
*
* Solution to homework assignment 3
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2019/2020
*
* @author Daniel Dimitrov Dimitrov
* @idnumber 62384
* @task 1
* @compiler VC
*
*/

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

struct Question {
	char text[100];
	char rightAnswer[100];
	char wrongAnswers[3][100];
};

const Question QUESTIONS[10] = {
	{"Who is the president of Djibouti?", "Ismail Omar Guelleh", {"Rosen Plevneliev", "Barack Obama", "Rumen Radev"}},
	{"What is the cube root of 1331?", "11", {"121", "1331", "21"}},
	{"What does \"harabiq\" mean", "really?", {"ailqk", "it's cold", "a type of mandja"}},
	{"How many hills are there in Plovdiv?", "6", {"7", "3", "5"}},
	{"How many hills used to be in Plovdiv?", "7", {"10", "6", "8"}},
	{"Which is the best town in Bulgaria?", "Varna", {"Varna", "Burgas", "Selo Kravino"}},
	{"Which is the best town in Bulgaria according to people from Gabrovo?", "Gabrovo", {"Plovdiv", "Sofia", "Burgas"}},
	{"Who much point would i get form this homework?", "7", {"2", "10", "5"}},
	{"Which is the meme of the year?", "blinking white guy", {"baby yoda", "storming area 51", "stonks"}},
	{"Which is the best football club?", "Liverpool", {"Barcelona", "Manchester United", "Chelsea"}},
};

const char WRONG_INPUT[] = "Wrong input. Please try again.";
const char INTRODUCTION_TEXT[] = "Hello, this is the Who Wants To Be A Billionaire game. The rules are simple: every question has 1 right and 3 wrong answers. If you answer correctly, you are one step closer to becoming a billionaire.\nCommands:\nN - next question\nQ - quit game\nJ - 50/50 joker";
const int NUMBER_OF_QUESTIONS = 10;
const int NUMBER_OF_ANSWERS = 4;
char RIGHT_ANSWER_TEXT[] = "Congratulations, your answer is correct!";
char WRONG_ANSWER_TEXT[] = "Sorry, your answer is incorrect. Better luck next time!";

void engine();
Question nextQuestion();
int randomNumber(int upperBoundary);
int printQuestion(Question question, bool joker, int indexOfRightAnswer = randomNumber(NUMBER_OF_ANSWERS));
char getAnswerFromUser(int indexOfRightAnswer, char resultText[100]);
void copy(char sourceArr[], char resultArr[]);

int main() {
	engine();
}

void engine() {
	std::cout << INTRODUCTION_TEXT << std::endl;

	while (true) {
		char cmd;
		std::cin >> cmd;

		int indexOfRightAnswer = 0;
		Question question;
		char userAnswer;

		char resultText[100];

		switch (cmd) {
		case 'Q': break;
		case 'N':
			question = nextQuestion();
			std::random_shuffle(std::begin(question.wrongAnswers), std::end(question.wrongAnswers)); // randomize wrong answers

			indexOfRightAnswer = printQuestion(question, false);

			userAnswer = getAnswerFromUser(indexOfRightAnswer, resultText);

			if (userAnswer == 'J') {
				printQuestion(question, true, indexOfRightAnswer);
				userAnswer = getAnswerFromUser(indexOfRightAnswer, resultText);
			}

			std::cout << resultText << std::endl;
			break;
		default:
			std::cout << WRONG_INPUT << std::endl;
			break;
		}
	}
}

Question nextQuestion() {
	int randomIndex = randomNumber(NUMBER_OF_QUESTIONS);

	return QUESTIONS[randomIndex];
}

int randomNumber(int upperBoundary) {
	srand(time(NULL)); //initialize the random seed

	int randomNumber = rand() % (upperBoundary); //generates a random number between 0 and the upper boundary

	return randomNumber;
}

int printQuestion(Question question, bool joker, int indexOfRightAnswer) {
	std::cout << question.text << std::endl;

	int indexOfWrongAnswers = 0;
	int randomWrongAnswerIndex = randomNumber(NUMBER_OF_ANSWERS - 1);

	for (size_t i = 0; i < 4; i++) {
		if (indexOfRightAnswer == i) {
			std::cout << (char)(i + 'A') << ": " << question.rightAnswer << std::endl;
		}
		else {
			if (joker && indexOfWrongAnswers != randomWrongAnswerIndex) {
				std::cout << std::endl;
				indexOfWrongAnswers++;
				continue;
			}
			std::cout << (char)(i + 'A') << ": " << question.wrongAnswers[indexOfWrongAnswers] << std::endl;
			indexOfWrongAnswers++;
		}
	}

	return indexOfRightAnswer;
}

char getAnswerFromUser(int indexOfRightAnswer, char resultText[100]) {
	char userAnswer;

	std::cin >> userAnswer;

	if (userAnswer - 'A' == indexOfRightAnswer) {
		copy(RIGHT_ANSWER_TEXT, resultText);
	}
	else {
		copy(WRONG_ANSWER_TEXT, resultText);
	}

	return userAnswer;
}

void copy(char sourceArr[], char resultArr[]) {
	int size = 0;

	for (size_t i = 0; sourceArr[i] != '\0'; i++) {
		resultArr[i] = sourceArr[i];
		size++;
	}

	resultArr[size] = '\0';
}
