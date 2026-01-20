# Read from the file file.txt and print its transposed content to stdout.
#datamash -t,transpose <file.txt>
awk '
{
    for (i = 1; i <= NF; i++) {
        a[i, NR] = $i
    }
}
END {
    for (i = 1; i <= NF; i++) {
        for (j = 1; j <= NR; j++) {
            printf "%s%s", a[i, j], (j == NR ? "" : " ")
        }
        print ""
    }
}' file.txt

