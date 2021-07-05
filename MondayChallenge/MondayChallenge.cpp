// MondayChallenge.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cctype>

// split string by list of delimeters
std::vector<std::string> split(std::string x, std::vector<char> delim)
{
    x += delim[0];
    std::vector<std::string> splitted;
    std::string temp = "";
    for (int i = 0; i < x.length(); i++)
    {
        for (int j = 0; j < delim.size(); j++) {

            if (x[i] == delim[j])
            {
                splitted.push_back(temp); //store words in "splitted" vector
                temp = "";
                i++;
            }
        }
        temp += x[i];
    }
    return splitted;
}

// string tolovercase
char asciitolower(char in) {
    if (in <= 'Z' && in >= 'A')
        return in - ('Z' - 'z');
    return in;
}


int main(int argc, char** argv)
{
    // TODO: relative path
    std::string path = "C:\\Users\\RIK\\source\\repos\\MondayChallenge\\x64\\Debug\\";

    // check input
    if (!argv[1]) {
        std::cout << "No console argument found" << std::endl;
        return 0;
    }
    std::string fileName = argv[1];

    std::unordered_map<std::string, int32_t> WordsMap;
    std::vector<char> delim{ '\'', ',', ' ', '.', '!', '?', '-' };

    std::ifstream source(path + fileName);

    // parse file
    if (source.is_open())
    {
        std::string line;
        while (getline(source, line)) {
            std::vector<std::string> words = split(line, delim);
            for (auto& word : words) {
                // TODO: validate word and split it in recursion way until it is not valid
                // word to lovercase
                std::transform(word.begin(), word.end(), word.begin(), asciitolower);
                // save word frequency
                WordsMap[word]++;
            }
        }
        source.close();
    }
    else {
        std::cout << "Text file: \" "<< path << " \" not found, or not valid" << std::endl;
    }

    // cout result
    for (auto const& [key, val] : WordsMap)
    {
        std::cout << key
            << ':'
            << val
            << std::endl;
    }
}

/* Output:

no:2
turn:1
went:1
three:3
into:3
case:1
chrysalis:1
-you:1
will:3
-and:2
open:1
with:3
door:1
after:3
butterfly:1
unpleasant:1
should:2
right:4
ll:3
feel:2
taller:1
little:5
change:1
queer:2
bit:5
your:8
feelings:1
puzzling:1
may:1
would:3
wretched:1
alice::1
me:3
contemptuously:1
'who:1
 which:1
william:3
brought:1
them:1
deal:1
spoke:1
together:1
again:7
making:1
beginning:2
felt:4
tone:1
irritated:1
s:1
such:3
suet;:1
short:1
remarks:1
waited:1
she:17
herself:4
 here:1
gravely:1
jaws:1
ought:1
tell:2
crawled:1
first:2
jaw:1
melancholy:1
why:1
clever:1
injure:1
question;:1
perfectly:2
as:18
did:2
before:2
could:2
struck:1
any:1
certainly::1
good:3
seemed:1
state:1
mind:2
turned:3
away:3
called:1
":2
important:1
hand:2
say:2
sounded:1
eat:1
sell:1
promising:1
 alice:5
came:2
somersault:1
keep:2
sure:1
swallowing:1
thought:3
wait:1
had:4
nothing:1
kick:1
worth:1
round:2
hearing:1
minutes:3
law:1
puffed:1
speaking:1
unfolded:1
arms:2
re:1
am:1
remember:2
things:2
son:1
same:1
mentioned:1
size:3
tried:1
"how:1
doth:1
busy:1
bee:1
particular:1
end:2
repeat:1
"you:1
piteous:1
old:5
locks:1
stand:1
father:4
folded:1
young:1
man:1
hair:1
 and:4
become:1
white;:1
incessantly:1
on:2
head:1
exactly:1
ointment:1
my:7
youth:6
 why:1
his:4
feared:1
brain;:1
 but:1
now:3
none:1
upright:1
'as:1
grown:1
box:1
most:1
 yet:3
only:1
 pray:2
sage:1
he:1
grey:1
far:1
limbs:1
supple:1
 by:1
use:1
rapidly;:1
shilling:1
 allow:1
couple:1
'and:1
too:1
speak:2
weak:1
goose:1
bones:1
beak:1
how:1
wife;:1
strength:1
height:2
which:4
gave:1
balanced:1
 has:1
life:2
'one:2
 that:1
suppose:1
eye:1
steady:1
words:1
ever;:1
difficult:1
eel:1
nose:1
 what:1
made:1
awfully:1
answered:1
questions:1
two:2
enough:1
 said:1
father;:1
'don:1
high):1
give:1
were:1
airs:1
began:1
if:2
listen:1
 be:1
stairs:1
quite:1
wrong:1
decidedly:1
silence:1
want:1
asked:2
trying:1
oh:1
hastily:1
replied;:1
one:2
room:1
doesn:1
managed:1
like:2
changing:1
sides:1
often:1
 she:2
nibbled:1
never:1
contradicted:1
losing:1
larger:1
wouldn:2
inches:2
indeed:1
angrily:1
rearing:1
itself:2
pleaded:1
offended:1
wish:1
creatures:1
easily:1
get:1
smoking:1
until:1
chose:1
minute:2
once:2
twice:1
remarking:1
side:4
make:3
grow:2
aloud;:1
however:1
moment:2
sight:1
remained:1
looking:1
it;:1
question:1
go:1
broke:1
edge:1
effect::1
next:1
violent:1
lefthand:1
blow:1
morsel:1
underneath:1
chin::1
foot:2
frightened:1
lost:1
shrinking:1
set:1
work:1
chin:1
closely:1
against:1
mouth;:1
swallow:1

*/