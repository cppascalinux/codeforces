while true; do
	./gen
	./lct
	./lct1
	if diff lct.out lct1.out; then
		echo "AC"
	else
		echo "WA"
		exit 0
	fi
done