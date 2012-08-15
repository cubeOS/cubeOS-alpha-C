/* cubeos.h core C library */
/* Developed by SamTechnologeek */
#ifndef CUBEOS_H
#define CUBEOS_H

/* ### system_restart () Reboots the system **UNDER DEVELOPMENT** */
void system_restart (void);
/* ### system_crash() Bind a new screen, yields "CubeOS has crashed" */
void system_crash (void);
/* ### ext() Exits subroutine filling A with 0 (TRUE) */
int ext (void);
/* ### exf() Exits a subroutine filling A with 0 (FALSE) */
int exf (void);
/* ### dview_init() Start dview */ 
void dview_init (void);
/* ### dview_newScreen() Initializes a new screen mapping for the currently
   running process,
   adjusts the dview pointers to work with this new screen, and remaps the
   screen.
   ** RETURNS screen location ** */
int dview_newScreen (void);
/* ### dview_close() Closes the latest window for the currently running process
   remapping to the one opened before that. */
void dview_close (void); 
/* ### dview_getLoc(x_cord, y_cord) Gets the memory location of the current
   screen at point (x_cord, y_cord).
   ** RETURNS memory location of the current screen point (x_cord, y_cord) ** */
int dview_getLoc (int x_cord, int y_cord);
/* ### dview_litWrite(x_cord, y_cord, input_pointer) Copies the null-terminated
   string, starting at input_pointer on the current screen.
   ** RETURNS the screen location following the written text. */
int dview_litWrite (int x_cord,int y_cord,int input_pointer);
/* ### dview.write (outputPointer, inputPointer)
   Writes ASCII to the current screen using special characters to act as
   directives (see below.) (This does not perform preprocessing such as
   translating normal ASCII into those special characters.) Special characters
   are as follows.
   ** RETURNS the screen location following the written text ** */
int dview_write (int output_pointer, int input_pointer);
/* ### dview.prompt (output_pointer, input_pointer, text_output)
   Uses *dview.write* to write a prompt (from *inputPointer*) to *screenOutputPointer*.
   ** RETURNS the screen location following the last user-entered key ** */
int dview_prompt (int output_pointer, int input_pointer, int text_output);
/* ### check.all (output_location)
 Checks all modules listed below, and writes a DView-formatted c-string to *outputLocation*,
 containing the name of each functionality checked and the exit status (with 0 being implicit on 
strings printed green.)
** MODIFIES A **
** RETURNS the total exit status (0 if all successful, 1 if otherwise) ** */
int check_all (int output_location);

#endif /*cubeos.h */