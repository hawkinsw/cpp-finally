Simple "finally" support for C++ Exceptions

A header-only class that adds hacky support
for "finally" blocks in C++.

The idea is to use RAII and destructors to 
invoke the finally block when a try/catch
clause goes out of scope. The TryFinally
class, when constructed anonymously, is
immediately constructed and then immediately
goes out of scope (destructed). This makes
it possible to execute the try block,
then immediately execute the finally block. 

Block is a macro that evaluates to \[&\]().
Using a typedef for this is not possible
since, apparently, \[&\]() does not name a type.

Try and Finally are std::function's that
make it possible to pass Block's as parameters.

It would be nice to be able to define the catch
clauses as parameters to TryFinally as well.
In the example you can see that it is a little 
clunky saying try twice in a row if you actually 
use exceptions in the Try block.
