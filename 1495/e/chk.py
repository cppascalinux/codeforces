import os
while True:
	os.system('./gen > e.in')
	os.system('./e < e.in > e.out')
	os.system('./bf < e.in > bf.out')
	s1=open('e.out',mode='r').read()
	s2=open('bf.out',mode='r').read()
	if s1!=s2:
		print('WA')
		break
	else:
		print('AC')
