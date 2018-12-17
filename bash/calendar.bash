function dayOfWeek {
  let "a = (14 - $2) / 12"
  let "y = $3 - $a"
  let "m = $2 + 12 * $a - 2"
  let "res = ($1 + $y + $y / 4 - $y / 100 + $y / 400 + (31 * $m) / 12) % 7"
  return $res
}

function daysInYear {
    let "year_num = $1"
    
    if [ $(expr $year_num % 4 ) -eq 0 ]
    then
        if [ $(expr $year_num % 100) -eq 0 ] && [ $(expr $year_num % 400) -gt 0 ]
        then
            echo "365"
        else
            echo "366"
        fi
    else
        echo "365"
    fi
}

let "sigint_trapped = 0"

function sigintHandler {
    let "sigint_trapped++"
    echo "You pressed Ctrl+C $sigint_trapped times!"
    if [ $sigint_trapped -gt 2 ]
    then
        echo "Print the Year!"
        read requestYear
        echo "Number of days in this year:"
        daysInYear $requestYear
    fi
}


trap sigintHandler SIGINT

cal

echo "Print day of current month and I'll print you for it's day of week"
read requestDay 

dayOfWeek $requestDay 12 2018
echo $?

kill -2 $$
kill -2 $$
kill -2 $$
kill -2 $$