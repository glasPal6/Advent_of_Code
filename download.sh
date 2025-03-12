#!/bin/bash

year="${1:-2025}"

cookies_values=$(<cookies.txt)

url="https://adventofcode.com"
url_day="${url}/${year}/day"

mkdir AOC_Code
cd AOC_Code

# mkdir static
# curl "${url}/static/style.css" > static/style.css

mkdir -p ${year}
cd ${year}

for i in $(seq 25)
do
        mkdir $i
        # curl "${url_day}/${i}" > ${i}/index.html
        curl -b "$cookies_values" ${url_day}/${i}/input > ${i}/input.txt
done
