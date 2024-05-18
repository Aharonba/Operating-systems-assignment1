int function (int x);
int main ()
{
function(5);
return 0;
}

int function (int x){
    if(x=0)
    {
        return 5;
    
    }

    else
    {
        function(x);
    }
}