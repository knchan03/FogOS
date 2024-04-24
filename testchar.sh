# Standardized tests for testchar functions

#isdigit
echo Testing isdigit : c
testchar isdigit c
echo Testing isdigit : 4
testchar isdigit 4

#isalpha
echo Testing isalpha : c
testchar isalpha c
echo Testing isalpha : 4
testchar isalpha 4

#isupper
echo Testing isupper : c
testchar isupper c
echo Testing isupper : S
testchar isupper S

#islower
echo Testing islower : c
testchar islower c
echo Testing islower : S
testchar islower S

#toupper
echo Testing toupper : c
testchar toupper c
echo Testing toupper : 4
testchar toupper 4

#tolower
echo Testing tolower : C
testchar tolower C
echo Testing tolower : 4
testchar tolower 4

#ispunct
echo Testing ispunct : /
testchar ispunct /
echo Testing ispunct : 4
testchar ispunct 4

#isspace
echo Testing isspace : ' '
testchar isspace  

#charcount
echo Testing charcount | String : "onomatopoeia" | Char : "o"
testchar charcount onomatopoeia o
echo Testing charcount | String : "onomatopoeia" | Char : "z"
testchar charcount onomatopoeia z

#find indexes
echo Testing findindexes | String : "onomatopoeia" | Char : "o"
testchar findindexes onomatopoeia o
echo Testing findindexes | String : "onomatopoeia" | Char : "z"
testchar findindexes onomatopoeia z

#strpbrk
echo Testing strpbrk | String : "Hollywood" | Substring : "wo"
testchar strpbrk Hollywood wo

echo Testing strpbrk | String : "Hollywood" | Substring : "z"
testchar strpbrk Hollywood z


#strcount
echo Testing strcount | String : "Mississipi" | Substring : "ss"
testchar strcount Mississippi ss

echo Testing strcount | String : "Mississipi" | Substring : "river"
testchar strcount Mississippi river

echo End of test...
exit
