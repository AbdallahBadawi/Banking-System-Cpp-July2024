#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "clsCurrency.h"
#include "clsUtil.h"

class clsFindCurrencyScreen : clsScreen
{
private:
    
    enum enFindCurrencyOption
    {
        enFindByCode = 1, enFindByCountry = 2
    };

    static void _PrintCurrency(clsCurrency Currency)
    {
        cout << "\nCurrency Card:\n";
        cout << "_____________________________\n";
        cout << "\nCountry    : " << Currency.Country();
        cout << "\nCode       : " << Currency.CurrencyCode();
        cout << "\nName       : " << Currency.CurrencyName();
        cout << "\nRate(1$) = : " << Currency.Rate();

        cout << "\n_____________________________\n";

    }

    static void _ShowResults(clsCurrency Currency)
    {
        if (!Currency.IsEmpty())
        {
            cout << "\nCurrency Found :-)\n";
            _PrintCurrency(Currency);
        }
        else
        {
            cout << "\nCurrency Was not Found :-(\n";
        }
    }


public:

    static void ShowFindCurrencyScreen()
    {
        //if (!CheckAccessRights(clsUser::enPermissions::pFindClient))
        //{
        //    return;// this will exit the function and it will not continue
        //}

        _DrawScreenHeader("\tFind Currency Screen");
         
        cout << "\nFind By: [1] Code or [2] Country? ";
    
        enFindCurrencyOption UserOption = (enFindCurrencyOption) clsInputValidate::ReadShortNumberBetween(1, 2, "Invalid choice, Enter again\n");

        switch (UserOption)
        {
        case clsFindCurrencyScreen::enFindByCode:
        {
            cout << "\nPlease enter country code: ";
            string UserChoiceCountry = clsInputValidate::ReadString();
            clsCurrency CurrencyObject = clsCurrency::FindByCode(UserChoiceCountry);
            _ShowResults(CurrencyObject);
        }
            break;
        case clsFindCurrencyScreen::enFindByCountry:
        {
            cout << "\nPlease enter country Name: ";
            string UserChoiceCountry = clsInputValidate::ReadString();
            clsCurrency CurrencyObject = clsCurrency::FindByCountry(UserChoiceCountry);
            _ShowResults(CurrencyObject);
        }
            break;
        default:
            break;
        }
    }

};

