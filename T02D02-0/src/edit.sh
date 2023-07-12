# Edge case: not enough arguments
if [ "$1" = "" ] || [ "$2" = "" ] || [ "$3" = "" ]
then
  echo "[!] Not enough arguments."
  echo
  echo "Usage:"
  echo "  ./edit.sh <path_to_file> <string> <replacement>"
  echo
  echo "Example:"
  echo "  ./edit.sh src/history_of_vi.txt hello hi"
  exit 1  
fi

path="../$1"


# Edge case: file doesn't exist
if [ ! -f $path ]
then
  echo "[!] File $1 does not exist."
  exit 1
fi

# Text before update
before=""
line_count=$(awk 'END{print NR}' $path)

# Edge case: there is no lines in file
if [ $line_count = 0 ]
then
  echo "[!] File $path is empty."
  exit 1
fi


while IFS= read -r line
do
  before+="$line"
  line_count=$(($line_count-1))
  if [ $line_count != 0 ]
  then
    before+="\n"
  fi
done < $path

# Text after update
after=""
line_count=$(awk 'END{print NR}' $path)
while IFS= read -r line
do
  line_count=$(($line_count-1))
  buf=`echo "$line" | sed "s/$2/$3/g"`
  after+="$buf"
  if [ $line_count != 0 ]
  then
    after+="\n"
  fi
done < $path

# If file changed, then append the log
if [ "$before" != "$after" ]
then
  echo $after > $path

  SHA="$(shasum -a 256 $path | grep -oE '\b[0-9a-fA-F]+\b')"
  datetime_changed="$(date -r $path +'%Y-%m-%d %H:%M')"
  size="$(wc -c history_of_vi.txt | awk '{print $1}')"
  text="$1 - $size - $datetime_changed - $SHA - sha256"
  echo $text >> files.log
fi
