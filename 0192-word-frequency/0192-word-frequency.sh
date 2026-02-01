# Read from the file words.txt and output the word frequency list to stdout.
awk '
{
  for (i = 1; i <= NF; i++)
    freq[$i]++
}
END {
  for (w in freq)
    print w, freq[w]
}
' words.txt | sort -nr -k2
