Types of env/export tokens:
------------------------------
Full tokens (printable):
---------------
	65 + 
 - +0 full original token;
 - +1 full modified (must be freed)
 - +2 partially modified (value must be freed)
------------------------------
Partial tokens:
---------------
	98 + 
-	+0 (value with '=') - printable
-	+1 (value without '=') - not printable

==============================

Type of errors (checker):
--------------------------
Keys:
-------
not ft_isapha(x);
not '_'
--------------------------
Values:
-------
if no '=' - not printable for env
if started with ' ' is null
--------------------------