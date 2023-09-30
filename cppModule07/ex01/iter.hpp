#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

/*
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
*/

//template<class S>
template <typename S>
void iter(S a[], size_t len,void (*f)(const S&))
{
    if(a == NULL || f == NULL)
        return ;
    for(size_t x = 0; x < len; x++)
        f(a[x]);
}

template <typename S>
void iter(S a[], size_t len,void (*f)( S&))
{
    if(a == NULL || f == NULL)
        return ;
    for(size_t x = 0; x < len; x++)
        f(a[x]);
}


/*
template <typename B>
void iter2(B a[], size_t len, B (*f)(B&))
{
	if(a == NULL || f == NULL)
        return ;
    for(size_t x = 0; x < len; x++)
        std::cout << f(a[x]) << " ";
}
*/
#endif