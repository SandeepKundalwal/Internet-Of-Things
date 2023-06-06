if [ $# -ne 3 ]
then
    echo "bash script.sh arduino_data.csv 10 copy_1.csv"
    exit 0
fi

fname=$1
iteration=$2
for i in $(seq 1 $iteration); do
	new_fname="$3_$i.csv"
	echo "file: $fname"
	echo "will be concatenated $times times"
	echo "and saved as $new_fname"
	
	for j in $(seq 1 $i); do
		cat $fname >> $new_fname;
	done
done

