#ifndef PHONEBOOK_H
# define PHONEBOOK_H
# include <iostream>
# include <string>

class PhoneBook
{
	public:
		void	Add(void);
		void	Search(void);

	private:
		Contact	mBook[8];
		int		mIndex;
}


#endif