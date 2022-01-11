from os import system as sy
i=0
while True:
	sy('./gen>d.in;./std<d.in>std.out;./d<d.in>d.out')
	s1=open('std.out','r').read();
	s2=open('d.out','r').read();
	if s1==s2:
		print('AC',i)
	else:
		print('WA',i)
		exit(0)
