# Edge case: not enough arguments
if [ "$1" = "" ]
then
  echo "[!] Not enough arguments."
  echo
  echo "Usage:"
  echo "  ./log_analyzer.sh <path_to_log_file>"
  echo
  echo "Example:"
  echo "  ./log_analyzer.sh src/history_of_vi.txt"
  exit 1  
fi

path="../$1"
LOG_FILE="files.log"

# Edge case: file doesn't exist
if [ ! -f $path ]
then
  echo "[!] Log-file $path does not exist."
  exit 1
fi

line_count=$(awk 'END{print NR}' $path)
log_count=0
filenames=""
hashes=""

while IFS= read -r line
do
  line_count=$(($line_count-1))
  # Getting all the filenames
  filename="$(echo $line | cut -d ' ' -f 1)"


  # Getting all the SHA-256 hashes
  hash="$(echo $line | cut -d ' ' -f 8)"
  if [ "$line" != "" ] || [ "$line" != "\n" ]
  then
    # Append filenames and hashes to the string-lists
    filenames+="$filename"
    hashes+="$hash"

    # Incrementing overall count of logs
    log_count=$(($log_count+1))

    # Adding whitespaces
    if [ $line_count != 0 ]
    then
      filenames+="\n"
      hashes+="\n"
    fi
  fi
done < $path

unique_files_count="$(echo $filenames | sort | uniq -c | awk 'END{print NR}')"
unique_hashes_count="$(echo $hashes | sort | uniq -c | awk 'END{print NR}')"

echo $filenames
echo $hashes

echo "$log_count $unique_files_count $unique_hashes_count"