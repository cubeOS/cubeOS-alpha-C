/* cubeos.h core C library */
/* Developed by SamTechnologeek */
#ifndef CUBEOS_H
#define CUBEOS_H

/* C function for package making: ### package
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
/* ### dl.hashGet (search_term, hash_table_pointer)
   Searcher the hash table at *hash_table_pointer* for *search_term* in the lookup portion of it. It 
   returns the value in the value portion associated with the search_term.

   ** RETURNS value associated by the hash table with *search_term*, or 1 if it could not be found.
   ** DEVELOPMENT VERSION **
   */
/* UNSURE */ int dl_hashGet(char *search_term, int hash_table_pointer);
/* DL STUFF BEFORE THIS */
/* ### HWM()
   Maps the ports of all recongnized hardware to specific points in memory, which are accesible through
   labels. Upon recognizing a piece of hardware, it will map it to a memory location and do an automatic
   `JSR' to a label of the form `HWinit.x`, where *x* is the name of the hardware recognized in either 
   full form (`HWInit.LEM1802`) or definition camel case (`HWinit.GenericClock`) if the name of the 
   hardware cannot be represented by labels int its full form.
*/
void HWM (void);
/* ### HWF.1802 in as few cycles as possible and sets the memory location at the label *LEM1802* to
   its port number without mapping other hardware. This is intented to be run at bootime in order
   to quickly start the monitor and display a boot screen.
   ** UNDER DEVELOPMENT **
   */
void HWF_LEM1802 (void);
/* ### sh (pointer_command)
   Executes a single command pointed to by *pointer_command*
*/
void sh(int pointer_command);
/* ### crp.sum (input_pointer, input_length)
   Performs a BSD-checksum operation.
   ** RETURNS the 16 bit hash **
   */
int crp_sum(int input_pointer, int intput_lenght);
/* ### kd_newKeyboard (generic_keyboard)
   Defines a new keyboard in the first open memory location carried in *kd.daemonlist*, as defined
   *kd.init*, or adds a new one if it doesn't exist.
   ** RETURNS a pointer to the *generic_keyboard*'s OptLoc word.
   */
int kd_newKeyboard(int generic_keyboard);
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
int pih_chOSMsg (int msg, int location);
/* ### pih.newMsg (location)
   Finds the first unused message greater than or equal to 64, but less than or equal to 127. It then
   makes *location* the locattion to jump to when that interrupt is triggered.
   ** RETURNS the first open message **
   */
   

#endif /*cubeos.h */

