#ifndef CLSSCREEN_HPP
#define CLSSCREEN_HPP

#include "clsbankclient.hpp"
#include "clsUser.hpp"

class clsScreen
{
protected:
  static void _DrawScreenHeader(string Title, string Subtitle="");
  static bool _CheckAccessRights(clsUser::enPermissions Permission);
};
#endif /* CLSSCREEN_HPP */
