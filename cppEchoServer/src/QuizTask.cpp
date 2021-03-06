/*
 * ProtocolTask.cpp
 *
 *  Created on: Feb 6, 2017
 *      Author: LMA
 */
#include <sstream>
#include <iostream>
#include <array>
#include <functional> // for reference_wrapper
#include "QuizTask.h"
#include "Socket.h"

using namespace std;

namespace
{
	const int MAX_FOR_TEST{2};
	const int NUM_QUESTIONS{2};
	const array<string, NUM_QUESTIONS> QUESTIONS
	{
		"Pomerol is from?", "Malbec is from?"
	};
	const array<string, NUM_QUESTIONS> ANSWERS
	{
		"France", "Argentina"
	};
}

bool QuizTask::Execute(reference_wrapper<Socket> connectionSocketRef)
{
	Socket connectionSocket{ move(connectionSocketRef.get()) };
	int questionIndex{0};
	string messageReceived{""};
	while (messageReceived != "QUIT")
	{
		// this socket is used for both receive and send
		stringstream socketStream{ connectionSocket.Receive() };

		if (socketStream.rdbuf()->in_avail() == 0)
		{
			break;
		}

		socketStream >> messageReceived;

		cout << "messageReceived: " << messageReceived << endl;

		stringstream outputStream;
		if (messageReceived == "QUESTION") // will send back current question if quiz not completed
		{
			if (questionIndex >= MAX_FOR_TEST)
			{
				outputStream << "FINISHED";
				connectionSocket.Send(move(outputStream)); // send message to client we are finished

				cout << "Protocol Task completed" << endl;
				break;
			}

			outputStream << QUESTIONS[questionIndex];
		}
		else if (messageReceived == "ANSWER") // will send back answer based previous currentQuestion sent
		{
			string answer;
			socketStream >> answer;
			if (answer == ANSWERS[questionIndex])
			{
				outputStream << "You are correct";
			}
			else
			{
				outputStream << "Sorry, the correct answer is " <<  ANSWERS[questionIndex];
			}
			++questionIndex;
		}
		else
		{
			outputStream << "Unrecognized message! - " << messageReceived;
		}

		connectionSocket.Send(move(outputStream));
	}

	cout << "ProtocolTask::Execute exiting" << endl;
	return true;
}



