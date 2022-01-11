from os import system as sy
while True:
	sy('./gen >f.in')
	sy('./f <f.in >f.out')
	sy('./std <f.in >std.out')
	t1=open('f.out','r').read()
	t2=open('std.out','r').read()
	if t1==t2:
		print('AC')
	else:
		print('WA')
		break
