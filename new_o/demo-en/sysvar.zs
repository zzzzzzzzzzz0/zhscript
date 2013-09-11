#!../l -S syn-en -E err-en --;
define *^-^* = begin
	echo $(arg1){
		if has $(arg1) then
			`={$($(arg1))}'
		else
			<<< x>>>
	}{if has arg2 then
			$(arg2)
		else
			LF
	};
end;
alias @^-^@ = `*^-^*';
define LF [noarg] = `asc10';

*^-^* arg;
*^-^* arg-1; *^-^* arg.length;
*^-^* arg0;
eval $(*^-^*), arg0;

*^-^* [up]arg;
*^-^* [up]arg-1; *^-^* [up]arg.length;
*^-^* [up]arg0;

*^-^* [main]arg;
*^-^* [main]arg.length;
*^-^* [main]arg0;

*^-^* [top]arg;
*^-^* [top]arg.length;
*^-^* [top]arg0;

echo `args{';
echo $(args);
echo `}'LF;
if $(arg.length) > <<<1>>> then
	echo~~~`args2{$(args2)}' LF;

@^-^@ window;

with `@^-^@ `callback$(arg1)'' {
	`';
	0;
	1;
	2;
	3;
	4;
	5;
	6;
	7;
	8;
	9;
};

*^-^* keyword-1; *^-^* keyword.length;
*^-^* keyword1;
*^-^* keyword2;
*^-^* keyword$(keyword-1);
*^-^* keyword;

load lib-en/gjk4;
set i = 0;
for{
	set i = calc $(i)+1;
	if $(i) > $(keyword.length) then echo LFLF : break;
	*^-^* keyword$(i), ;
};
