#include <iostream>
#include <map>
#include <stdlib.h>
#include <iomanip>
using namespace std;

//item, amount, cost
map<string, pair<int, double> > inventory;
//id, item, amount
map<int, map<string, int> > carts;

map<string, string> names;

string to_lower(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] += 'a' - 'A';
        }
    }
    return s;
}

int main()
{
    //cout << to_lower("efjIJeijfidSEFA");
    //map<string, int> test;
    //test["e"];
    //test["f"];

    cout << fixed << setprecision(2);

    cout << 13.34234;

    int n;
    cin >> n;

    for (int z = 0; z < n; z++)
    {
        inventory.clear();

        int k, c;
        cin >> k >> c;

        for (int i = 0; i < k; i++)
        {
            int amount;
            string item;
            double cost;
            cin >> amount >> item >> cost;

            names[to_lower(item)] = item;
            item = to_lower(item);
            inventory[item] = {amount, cost};
        }

        for (int i = 0; i < c; i++)
        {
            int id;
            string cmd;
            cin >> id >> cmd;

            if (carts.find(id) == carts.end())
            {
                carts[id];
            }

            if (cmd == "ADD")
            {
                string item;
                int qty;
                cin >> item >> qty;
                item = to_lower(item);
                if (carts[id][item] + qty > inventory[item].first)
                {
                    cout << "Not enough " << names[item] << " for customer " << id << endl;
                }
                else
                {
                    carts[id][item] += qty;
                    cout << "Added " << qty << " " << names[item] << " to customer " << id << "'s cart" << endl;
                }
            }
            else if (cmd == "REMOVE")
            {
                string item;
                int qty;
                cin >> item >> qty;
                item = to_lower(item);
                if (carts[id][item] >= qty)
                {
                    carts[id][item] -= qty;
                    cout << "Removed " << qty << " " << names[item] << " from customer " << id << "'s cart" << endl;
                }
                else
                {
                    cout << "Customer " << id << " does not have that many " << names[item] << "s" << endl;
                }
            }
            else
            {
                float cost = 0;
                for (auto it = carts[id].begin(); it != carts[id].end(); it++)
                {
                    //cout << it->first << " " << it->second << endl;
                    string temp = names[it->first];
                    if (it->second > inventory[it->first].first)
                    {
                        cout << "Out of stock of " << temp << endl;
                        it->second = 0;
                    }
                    else
                    {
                        cost += it->second * inventory[it->first].second;
                        inventory[it->first].first -= it->second;
                    }
                }
                cout << "Customer " << id << "'s total: $" << cost << endl;

//                        for (auto it = inventory.begin(); it != inventory.end(); it++)
//        {
//            cout << it->first << " - " << (it->second).first << endl;
//        }
            }
        }

        for (auto it = inventory.begin(); it != inventory.end(); it++)
        {
            if ((it->second).first != 0)
                cout << names[it->first] << " - " << (it->second).first << endl;
        }
    }
}

/*
1
3 8
2 Candy_Bar 1.50
3 Soda_Bottle 1.60
2 Cheese_Pack 2.50
1 ADD Candy_Bar 1
2 ADD Candy_Bar 2
1 ADD Soda_Bottle 3
1 REMOVE Soda_Bottle 4
2 CHECKOUT
1 CHECKOUT
3 ADD Candy_Bar 1
3 ADD Cheese_Pack 2
*/
