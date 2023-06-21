/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:09:44 by stunca            #+#    #+#             */
/*   Updated: 2023/05/20 15:42:05 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Account.hpp"
#include <iostream>
#include <ctime>


/*
./test > new.log
< new.log cut -d " " -f2 > new_no_timestamps.log
< 19920104_091532.log cut -d " " -f2 > old_no_timestamps.log
diff -s old_no_timestamps.log new_no_timestamps.log
*/

// STATIC INT
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

//GETTER
int Account::getNbAccounts(void){return Account::_nbAccounts;}
int Account::getTotalAmount(void){return Account::_totalAmount;}
int Account::getNbDeposits(void){return Account::_totalNbDeposits;}
int Account::getNbWithdrawals(void){return Account::_totalNbWithdrawals;}

//CONST-DEST

Account::Account(void) : _accountIndex(_nbAccounts),_amount(0),_nbDeposits(0),
_nbWithdrawals(0) 
{
	Account::_nbAccounts++;
}
/*
Account::Account(void)
{
    _accountIndex = _nbAccounts;
    _amount = 0;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    Account::_nbAccounts++;
    //Account:: ->for statics. If you don't use Account:: with static variables, compiler thinks there is a local variable which has same name but if compiler does not found a local variable which same name, compiler searches static variable.
}
*/


Account::Account(int initial_deposit) : _accountIndex(_nbAccounts),_amount(initial_deposit),_nbDeposits(0),_nbWithdrawals(0) 
{
	Account::_nbAccounts++;
	Account::_totalAmount += _amount;
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex << ";"
				<< "amount:" <<_amount << ";"
				<< "created" << std::endl;
}

Account::~Account(void)	{
	Account::_nbAccounts--;
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex << ";"<< "amount:" << _amount << ";"<< "closed" << std::endl;
}

/*	Displays a timestamp of the current date and time followed by a space.
	Format : [YEARMONTHDAY_HOURMINSEC]	*/
/*
struct tm :
tm_sec: Sec (0-59 ).
tm_min: Min (0-59 ).
tm_hour: H (0-23 ).
tm_mday: Mont.'s days(1-31 ).
tm_mon: Month (0-11 a, Jan 0, Dec 11).
tm_year: Year 
tm_wday: weekdays (0-6 , sunday 0, saturday 6).
tm_yday: Year's days(1-365 or 1-366 ).

*/
/*
std::time(&rawTime); ifadesi, sistem saatini temsil eden rawTime değişkenine güncel zaman bilgisini atar. std::time fonksiyonu, time_t türündeki bir değişkene zamanın geçen saniyelerini atar. Bu, genellikle 1970-01-01 00:00:00 UTC'den geçen saniyelerin sayısıdır.
*/
void	Account::_displayTimestamp( void ) {
	std::time_t	rawTime; //signed long or signed long long 
	struct tm	*timeInfo;

	std::time(&rawTime);
	timeInfo = localtime(&rawTime);

	std::cout << "[" << timeInfo->tm_year + 1900;
	if (timeInfo->tm_mon < 10)
		std::cout << "0";
	std::cout << timeInfo->tm_mon;
	if (timeInfo->tm_mday < 10)
		std::cout << "0";
	std::cout << timeInfo->tm_mday << "_";
	if (timeInfo->tm_hour < 10)
		std::cout << "0";
	std::cout << timeInfo->tm_hour;
	if (timeInfo->tm_min < 10)
		std::cout << "0";
	std::cout << timeInfo->tm_min;
	if (timeInfo->tm_sec < 10)
		std::cout << "0";
	std::cout << timeInfo->tm_sec << "] ";
}
/*
std::time_t rawTime;: std::time_t türünde rawTime adında bir değişken tanımlanır. std::time_t genellikle zamanı temsil etmek için kullanılan bir tamsayı türüdür. Bu değişken, zaman bilgilerini depolamak için kullanılacak.

struct tm *timeInfo;: struct tm türünde timeInfo adında bir işaretçi tanımlanır. struct tm zaman bilgilerini tutan bir yapıdır. Bu işaretçi, zaman bilgilerine erişmek ve düzenlemek için kullanılacak.

std::time(&rawTime);: std::time() fonksiyonu çağrılarak geçerli zaman alınır ve rawTime değişkenine atanır. Bu fonksiyon, sistem saati tarafından temsil edilen zamanı saniye cinsinden döndürür.

timeInfo = localtime(&rawTime);: localtime() fonksiyonu çağrılarak rawTime değişkeninin değeri yerel zaman dilimine göre ayrıştırılır ve timeInfo işaretçisine atanır. localtime() fonksiyonu, struct tm yapısını kullanarak tarih, saat, gün, ay ve yıl gibi zaman bileşenlerini elde etmemizi sağlar. Bu işlev, geçerli zamanı yerel zaman dilimine çevirir ve işaretçi olarak döndürür.

Bu kod örneği, rawTime değişkeni aracılığıyla sistem saatinden geçerli zamanı alır ve timeInfo işaretçisi aracılığıyla bu zamanın ayrıntılarına erişim sağlar.
*/

int Account::checkAmount(void)const
{
    return (this->_amount);
}

void	Account::makeDeposit( int deposit ) {
	_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex << ";"<< "p_amount:" <<this->_amount << ";"<< "deposit:";
	this->_amount += deposit;
	Account::_totalAmount += deposit;
	this->_nbDeposits++;
	Account::_totalNbDeposits++;
	std::cout	<< deposit << ";"<< "amount:" << this->_amount << ";"<< "nb_deposits:" << this->_nbDeposits << std::endl;
}


bool	Account::makeWithdrawal( int withdrawal ) {
	_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex << ";"
				<< "p_amount:" << this->_amount << ";"
				<< "withdrawal:";
	if (withdrawal > this->_amount) {
		std::cout << "refused" << std::endl;
		return (false);
	}
	else {
		this->_amount -= withdrawal;
		Account::_totalAmount -= withdrawal;
		this->_nbWithdrawals++;
		Account::_totalNbWithdrawals++;
		std::cout	<< withdrawal << ";"
					<< "amount:" << this->_amount << ";"
					<< "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	}
	return (true);
}

void	Account::displayStatus( void ) const {
	_displayTimestamp();
	std::cout	<< "index:"		<< _accountIndex << ";"
				<< "amount:"	<<_amount << ";"
				<< "deposits:"	<< _nbDeposits << ";"
				<< "withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout	<< "accounts:"	<< getNbAccounts() << ";"
				<< "total:"		<< getTotalAmount()	<< ";"
				<< "deposits:"	<< getNbDeposits() << ";"
				<< "withdrawals:" << getNbWithdrawals() << std::endl;
}
