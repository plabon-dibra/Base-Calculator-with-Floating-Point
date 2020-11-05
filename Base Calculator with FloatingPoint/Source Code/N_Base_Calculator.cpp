#include<bits/stdc++.h>
#define ll long long int
using namespace std;
string number,ans="",op;
stack<ll>st,st2;
ll n,r;
double m,d=0.0;
int mainMenu()
{
    system("cls");
    cout<<"1.  Decimal to Binary"<<endl;
    cout<<"2.  Decimal to Octal"<<endl;
    cout<<"3.  Decimal to HexaDecimal\n"<<endl;

    cout<<"4.  Binary to octal"<<endl;
    cout<<"5.  Binary to Decimal"<<endl;
    cout<<"6.  Binary to HexaDecimal\n"<<endl;

    cout<<"7.  Octal to Binary"<<endl;
    cout<<"8.  Octal to Decimal"<<endl;
    cout<<"9.  Octal to HexaDecimal\n"<<endl;

    cout<<"10. HexaDecimal to Binary"<<endl;
    cout<<"11. HexaDecimal to Octal"<<endl;
    cout<<"12. HexaDecimal to Decimal\n "<<endl;

    cout<<"0.  To Exit.\n"<<endl;
    cout<<"=>  Enter Your choice:    ";
    int choice;
    cin>>choice;
    return choice;
}





void to_ll()
{
    n=0;
    d=0;
    double dl=0.1;
    bool f=false;
    for(int i=0; i<number.size(); i++)
    {
        r=number[i]-48;
        if(r<0)
        {
            f=true;
            continue;
        }
        if(f==false)
            n=n*10 + r;
        else
        {
            d=d + dl*r;
            dl*=.1;
        }
    }
}




string toString(ll nm)
{
    switch(nm)
    {
    case 0:
        return "0";
        break;
    case 1:
        return "1";
        break;
    case 2:
        return "2";
        break;
    case 3:
        return "3";
        break;
    case 4:
        return "4";
        break;
    case 5:
        return "5";
        break;
    case 6:
        return "6";
        break;
    case 7:
        return "7";
        break;
    case 8:
        return "8";
        break;
    case 9:
        return "9";
        break;
    case 10:
        return "A";
        break;
    case 11:
        return "B";
        break;
    case 12:
        return "C";
        break;
    case 13:
        return "D";
        break;
    case 14:
        return "E";
        break;
    case 15:
        return "F";
        break;
    }
}




void decimal_to_N_base(int base)
{
    to_ll();

    while(n)
    {
        st.push(n%base);
        n/=base;
    }

    while(!st.empty())
    {
        ans+=toString(st.top());
        st.pop();
    }
    if(d!=0.0)
    {
        ans+=".";
        for(int i=1; i<=5; i++)
        {
            d=(double)d*base;
            n=(ll)d;
            m=(double)n;
            d-=m;
            ans+=toString(n);
        }
    }
}





ll power(ll base,int p)
{
    ll nm=1;
    while(p--)
    {
        nm*=base;
    }
    return nm;
}




void n_base_to_decimal(int base)
{
    d=0.0;
    n=0;
    int flag=-1,p;
    for(int i=0; i<number.size(); i++)
    {
        if(number[i]==46)
        {
            flag=i;
            break;
        }
    }
    if(flag==-1)
    {
        p=number.size()-1;
        for(int i=0; i<number.size(); i++)
        {
            n+=(number[i]-48)*power(base,p);
            p--;
        }
        if(base==2)
            cout<<"("<<number<<")2   =   ("<<n<<")10"<<endl;
        else if(base ==8)
            cout<<"("<<number<<")8   =   ("<<n<<")10"<<endl;
        else if(base==16)
            cout<<"("<<number<<")16   =   ("<<n<<")10"<<endl;
    }
    else
    {
        p=flag-1;
        for(int i=0; i<flag; i++)
        {
            if(number[i]>=65&&number[i]<=70)
                n+=((number[i]-55)*power(base,p));
            else
                n+=((number[i]-48)*power(base,p));
            p--;
        }
        p=-1;
        for(int i=flag+1; i<number.size(); i++)
        {
            if(number[i]>=65&&number[i]<=70)
                d+=((number[i]-55)*pow(base,p));
            else
                d+=((number[i]-48)*pow(base,p));
            p--;
        }
        m=(double)n;
        d+=m;
        if(base==2)
            cout<<"("<<number<<")2   =   ("<<d<<")10"<<endl;
        else if(base ==8)
            cout<<"("<<number<<")8   =   ("<<d<<")10"<<endl;
        else if(base==16)
            cout<<"("<<number<<")16   =   ("<<d<<")10"<<endl;
    }
}




string to_bit_3(char c)
{
    switch(c)
    {
    case '0':
        return "000";
        break;
    case '1':
        return "001";
        break;
    case '2':
        return "010";
        break;
    case '3':
        return "011";
        break;
    case '4':
        return "100";
        break;
    case '5':
        return "101";
        break;
    case '6':
        return "110";
        break;
    case '7':
        return "111";
        break;
    }
}




string to_bit_4(char c)
{
    switch(c)
    {
    case '0':
        return "0000";
        break;
    case '1':
        return "0001";
        break;
    case '2':
        return "0010";
        break;
    case '3':
        return "0011";
        break;
    case '4':
        return "0100";
        break;
    case '5':
        return "0101";
        break;
    case '6':
        return "0110";
        break;
    case '7':
        return "0111";
        break;
    case '8':
        return "1000";
        break;
    case '9':
        return "1001";
        break;
    case 'A':
        return "1010";
        break;
    case 'B':
        return "1011";
        break;
    case 'C':
        return "1100";
        break;
    case 'D':
        return "1101";
        break;
    case 'E':
        return "1110";
        break;
    case 'F':
        return "1111";
        break;
    }
}





void n_base_to_binary(int base)
{
    //Octal & HexaDecimal
    ans="";
    for(int i=0; i<number.size(); i++)
    {
        if(number[i]==46)
        {
            ans+=".";
            continue;
        }
        if(base==8)
            ans+=to_bit_3(number[i]);
        else
            ans+=to_bit_4(number[i]);
    }
}





string to_string_3_4_bit(string c)
{
    if(c=="000"||c=="0000")
        return "0";
    else if(c=="001"||c=="0001")
        return "1";
    else if(c=="010"||c=="0010")
        return "2";
    else if(c=="011"||c=="0011")
        return "3";
    else if(c=="100"||c=="0100")
        return "4";
    else if(c=="101"||c=="0101")
        return "5";
    else if(c=="110"||c=="0110")
        return "6";
    else if(c=="111"||c=="0111")
        return "7";
    else if(c=="1000")
        return "8";
    else if(c=="1001")
        return "9";
    else if(c=="1010")
        return "A";
    else if(c=="1011")
        return "B";
    else if(c=="1100")
        return "C";
    else if(c=="1101")
        return "D";
    else if(c=="1110")
        return "E";
    else if(c=="1111")
        return "F";
    return "";
}





void binary_to_n_base(int base)
{
    //Octal & HexaDecimal
    int nn=0,flag=-1,cnt=0;
    string str="";
    stack<string>ststr,emp;
    if(base==8)
        nn=3;
    else if(base==16)
        nn=4;
    else
    {
        cout<<"Error"<<endl;
        return;
    }

    for(int i=0; i<number.size(); i++)
    {
        if(number[i]==46)
        {
            flag=i;
            break;
        }
    }
    if(flag!=-1)
    {
        for(int i=flag-1; i>=0; i--)
        {
            cnt++;
            str+=toString(number[i]-48);
            if(cnt==nn)
            {
                reverse(str.begin(),str.end());
                ststr.push(to_string_3_4_bit(str));
                str="";
                cnt=0;
            }
        }
        if(cnt!=0)
        {
            for(int i=cnt+1; i<=nn; i++)
            {
                str+="0";
            }
            reverse(str.begin(),str.end());
            ststr.push(to_string_3_4_bit(str));
        }
        while(!ststr.empty())
        {
            ans+=ststr.top();
            ststr.pop();
        }

        cnt=0;
        str="";
        ans+=".";
        for(int i=flag+1; i<number.size(); i++)
        {
            cnt++;
            str+=toString(number[i]-48);
            if(cnt==nn)
            {
                ans+=to_string_3_4_bit(str);
                str="";
                cnt=0;
            }
        }

        if(cnt!=0)
        {
            for(int i=cnt+1; i<=nn; i++)
            {
                str+="0";
            }
            ans+=to_string_3_4_bit(str);
        }
    }
    else
    {
        for(int i=number.size()-1; i>=0; i--)
        {
            cnt++;
            str+=toString(number[i]-48);
            if(cnt==nn)
            {
                reverse(str.begin(),str.end());
                ststr.push(to_string_3_4_bit(str));
                str="";
                cnt=0;
            }
        }
        if(cnt!=0)
        {
            for(int i=cnt+1; i<=nn; i++)
            {
                str+="0";
            }
            reverse(str.begin(),str.end());
            ststr.push(to_string_3_4_bit(str));
        }
        while(!ststr.empty())
        {
            ans+=ststr.top();
            ststr.pop();
        }
    }
}




void octal_to_hexadecimal()
{
    n_base_to_binary(8);
    number=ans;
    ans="";
    binary_to_n_base(16);
}




void hexadecimal_to_octal()
{
    n_base_to_binary(16);
    number=ans;
    ans="";
    binary_to_n_base(8);
}

bool valid(int choice)
{
    int base;
    if(choice>=1&&choice<=3)
        base=10;
    else if(choice>3&&choice<7)
        base=2;
    else if(choice>6&&choice<10)
        base=8;
    else if(choice>9&&choice<13)
        base=16;
    else
        return false;
    for(int i=0; i<number.size(); i++)
    {
        if(base==16)
        {
            if(number[i]>='A'&&number[i]<='F'  ||   number[i]>=48 &&number[i]<=57   ||number[i]==46)
                continue;
            else
                return false;
        }
        else
        {
            if(number[i]>=48&&number[i]<48+base   ||  number[i]==46)
                continue;
            else
                return false;

        }
    }
    return true;
}


int main()
{
    while(int choice=mainMenu())
    {
        if(choice<0 || choice>12)
        {
            cout<<"Invalid Choice !"<<endl;
            getchar();
            getchar();
            continue;
        }
        else
        {
        cout<<"\n\nEnter The Number: "<<endl;
        cin>>number;
        }
        if(valid(choice))
        {
            switch(choice)
            {
            case 1:
                decimal_to_N_base(2);
                cout<<"("<<number<<")10   =   ("<<ans<<")2"<<endl;
                break;
            case 2:
                decimal_to_N_base(8);
                cout<<"("<<number<<")10   =   ("<<ans<<")8"<<endl;
                break;
            case 3:
                decimal_to_N_base(16);
                cout<<"("<<number<<")10   =   ("<<ans<<")16"<<endl;
                break;
            case 4:
                binary_to_n_base(8);
                cout<<"("<<number<<")2   =   ("<<ans<<")8"<<endl;
                break;
            case 5:
                n_base_to_decimal(2);
                break;
            case 6:
                binary_to_n_base(16);
                cout<<"("<<number<<")2   =   ("<<ans<<")16"<<endl;
                break;
            case 7:
                n_base_to_binary(8);
                cout<<"("<<number<<")8   =   ("<<ans<<")2"<<endl;
                break;
            case 8:
                n_base_to_decimal(8);
                break;
            case 9:
                op=number;
                octal_to_hexadecimal();
                cout<<"("<<op<<")8   =   ("<<ans<<")16"<<endl;
                break;
            case 10:
                n_base_to_binary(16);
                cout<<"("<<number<<")16   =   ("<<ans<<")2"<<endl;
                break;
            case 11:
                op=number;
                hexadecimal_to_octal();
                cout<<"("<<op<<")16   =   ("<<ans<<")8"<<endl;
                break;
            case 12:
                n_base_to_decimal(16);
                break;
            }
        }
        else
            cout<<"Wrong Input!"<<endl;

        number="";
        ans="";
        st=st2;
        getchar();
        getchar();
    }


    return 0;
}
