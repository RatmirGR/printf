<h3>Project name:</h3>
<h2> printf</h2>

<p><img src="https://github.com/RatmirW/RatmirW/blob/main/images/job-seeking.png" height="24" hspace="10" vspace="10"/><b>Project description:</b></p>
This exercise is a great opportunity to improve your programming skills. It will introduce you to variadic functions in C. The key to the success of ft_printf is well-structured and extensible code.

<p><img src="https://github.com/RatmirW/RatmirW/blob/main/images/task.png" height="24" hspace="10" vspace="10"/><b>Task:</b></p>
<p>You have to recode the printf() function from libc. The prototype of ft_printf() is:</p>
  <p> int ft_printf(const char *, ...);</p>

<p>Here are the requirements:</p>
<p>• Don’t implement the buffer management of the original printf().</p>
<p>• Your function has to handle the following conversions: cspdiuxX%</p>
<p>• Your function will be compared against the original printf().</p>
<p>• You must use the command ar to create your library. Using the libtool command is forbidden.</p>
<p>• Your libftprintf.a has to be created at the root of your repository</p>

<p>You have to implement the following conversions:</p>
<p>• %c Prints a single character.</p>
<p>• %s Prints a string (as defined by the common C convention).</p>
<p>• %p The void * pointer argument has to be printed in hexadecimal format.</p>
<p>• %d Prints a decimal (base 10) number.</p>
<p>• %i Prints an integer in base 10.</p>
<p>• %u Prints an unsigned decimal (base 10) number.</p>
<p>• %x Prints a number in hexadecimal (base 16) lowercase format.</p>
<p>• %X Prints a number in hexadecimal (base 16) uppercase format.</p>
<p>• %% Prints a percent sign.</p>


<p><img src="https://github.com/RatmirW/RatmirW/blob/main/images/bonus2.png" height="32"/>Bonus part</p>
<p>• Manage any combination of the following flags: ’-0.’ and the field minimum width under all conversions.</p>
<p>• Manage all the following flags: ’# +’ (Yes, one of them is a space)</p>
