#ifndef INPUT_H
#define INPUT_H

int  safe_input_int(const char *prompt, int min, int max);
void safe_input_string(char *buffer, int size, const char *prompt);
int  safe_input_yes_no(const char *prompt);
int  safe_input_choice_pipick(const char *prompt);

#endif
