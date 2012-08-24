/* cubeos.h core C library */
/* Developed by SamTechnologeek */
#ifndef CUBEOS_H
#define CUBEOS_H

typedef unsigned short int Uint16;

/* ### system_restart () Reboots the system **UNDER DEVELOPMENT** */
void system_restart (void);
/* ### system_crash() Bind a new screen, yields "CubeOS has crashed" */
void system_crash (void);
/* ### dview_init() Start dview */ 
void dview_init (void);
/* ### dview_newScreen() Initializes a new screen mapping for the currently
   running process,
   adjusts the dview pointers to work with this new screen, and remaps the
   screen.
   ** RETURNS screen location ** */
Uint16 dview_newScreen (void);
/* ### dview_close() Closes the latest window for the currently running process
   remapping to the one opened before that. */
void dview_close (void); 
/* ### dview_getLoc(x_cord, y_cord) Gets the memory location of the current
   screen at point (x_cord, y_cord).
   ** RETURNS memory location of the current screen point (x_cord, y_cord) ** */
Uint16 dview_getLoc (Uint16 x_cord, Uint16 y_cord);
/* ### dview_litWrite(x_cord, y_cord, input_pointer) Copies the null-terminated
   string, starting at input_pointer on the current screen.
   ** RETURNS the screen location following the written text. */
Uint16 dview_litWrite (Uint16 x_cord,Uint16 y_cord,Uint16 input_pointer);
/* ### dview.write (outputPointer, inputPointer)
   Writes ASCII to the current screen using special characters to act as
   directives (see below.) (This does not perform preprocessing such as
   translating normal ASCII into those special characters.) Special characters
   are as follows.
   ** RETURNS the screen location following the written text ** */
Uint16 dview_write (Uint16 output_pointer, Uint16 input_pointer);
/* ### dview.prompt (output_pointer, input_pointer, text_output)
   Uses *dview.write* to write a prompt (from *inputPointer*) to *screenOutputPointer*.
   ** RETURNS the screen location following the last user-entered key ** */
Uint16 dview_prompt (Uint16 output_pointer, Uint16 input_pointer, Uint16 text_output);
/* ### check.all (output_location)
 Checks all modules listed below, and writes a DView-formatted c-string to *outputLocation*,
 containing the name of each functionality checked and the exit status (with 0 being implicit on 
strings printed green.)
** MODIFIES A **
** RETURNS the total exit status (0 if all successful, 1 if otherwise) ** */
Uint16 check_all (Uint16 output_location);
/* ### dl.hashGet (search_term, hash_table_pointer)
   Searcher the hash table at *hash_table_pointer* for *search_term* in the lookup portion of it. It 
   returns the value in the value portion associated with the search_term.

   ** RETURNS value associated by the hash table with *search_term*, or 1 if it could not be found.
   ** DEVELOPMENT VERSION **
   */
/* UNSURE */ Uint dl_hashGet(Uint16 search_term, Uint16 hash_table_pointer);
/* DL STUFF BEFORE THIS */
/* ### sh (pointer_command)
   Executes a single command pointed to by *pointer_command*
*/
void sh(Uint16 pointer_command);
/* ### crp.sum (input_pointer, input_length)
   Performs a BSD-checksum operation.
   ** RETURNS the 16 bit hash **
   */
Uint16 crp_sum(Uint16 input_pointer, Uint16 intput_lenght);
/* ### kd_newKeyboard (generic_keyboard)
   Defines a new keyboard in the first open memory location carried in *kd.daemonlist*, as defined
   *kd.init*, or adds a new one if it doesn't exist.
   ** RETURNS a pointer to the *generic_keyboard*'s OptLoc word.
   */
Uint16 kd_newKeyboard(Uint16 generic_keyboard);
/* ### pih_init()
   Does `IAS pih` to direct any interrupts to the interrupt handler.
*/
void pih_init (void);
/* ### pih_return ()
   Exits the interrupt handler, returning the value that is currently in A in the register A (avoiding
   clearing it during the return process.)
   ** SYNTAX `SET PC, pih.returnVal` to exit **
   */
void pih_return (void);
/* ### pih_chOSMsh (msg, location)
   Redefines the OS (msg < 64) interrupt message to point at *location*
   ** MODIFIES A **
   ** RETURNS *msg **
   */
Uint16 pih_chOSMsg (Uint16 msg, Uint16 location);
/* ### pih.newMsg (location)
   Finds the first unused message greater than or equal to 64, but less than or equal to 127. It then
   makes *location* the locattion to jump to when that interrupt is triggered.
   ** RETURNS the first open message **
   */
Uint16 pih_newMsg (Uint16 location);   

#endif /*cubeos.h */

