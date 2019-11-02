//

#ifndef PRUEBA_CLIENT_H
#define PRUEBA_CLIENT_H

#include "prueba.h"

void checkCommandLineArguments(int argc, char *argv[]);
void wrongInputMessage(char *programName);
int parseOperation(char *operation, char *programName);
CLIENT * createClient(char *host);
void callServerFunction(CLIENT *client, int operation, operandos *numbers);
void callAdditionFunction(CLIENT *client, operandos *numbers);
void callSubstractionFunction(CLIENT *client, operandos *numbers);
void callMultiplicationFunction(CLIENT *client, operandos *numbers);
void callDivisionFunction(CLIENT *client, operandos *numbers);

#endif // PRUEBA_CLIENT_H