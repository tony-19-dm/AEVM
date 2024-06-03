#!/bin/bash
# acs_chars=``aaffggiijjkkllmmnnooppqqrrssttuuvvwwxxyyzz{{||}}~~
# enter_alt_charset_mode=\E(0
# exit_alt_charset_mode=\E(B
start_row=10
start_col=5
rows=8
# Clear screen
echo -e '\033[2J\033[H'

# enter alt charset mode
echo -e '\E(0'
# top horizontal line
echo -e '\033[10;6Hqqqqqq'
echo -e '\033[10;5Hl'
echo -e '\033[10;12Hk'
# vertical lines
for ((i=0; i<$((${rows} - 1)); i++)); do
    echo -e "\033[$((${start_row} + i + 1));${start_col}Hx"
done
for ((i=0; i<$((${rows} - 1)); i++)); do
    echo -e "\033[$((${start_row} + i + 1));$((${start_col} + 7))Hx"
done
# bottom horizontal line
echo -e '\033[18;6Hqqqqqq'
echo -e '\033[18;5Hm'
echo -e '\033[18;12Hj'

# Birthday date
echo -e '\033[12;8Haaaa'
for ((i=12; i < 13; i++)); do
    echo -e "\033[$((i));$((6))Haa"
done
for ((i=13; i < 18; i++)); do
    echo -e "\033[$((i));$((10))Haa"
done

#exit alt charset mode
echo -e '\E(B'

