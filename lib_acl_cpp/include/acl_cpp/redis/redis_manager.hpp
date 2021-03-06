#pragma once
#include "acl_cpp/acl_cpp_define.hpp"
#include "acl_cpp/connpool/connect_manager.hpp"

namespace acl
{

class ACL_CPP_API redis_manager : public connect_manager
{
public:
	/**
	 * 构造函数
	 * @param conn_timeout {int} 服务器连接超时时间(秒)
	 * @param rw_timeout {int}　网络 IO 读写超时时间(秒)
	 */
	redis_manager(int conn_timeout, int rw_timeout);
	virtual ~redis_manager();

protected:
	/**
	 * 基类纯虚函数，用来创建连接池对象
	 * @param addr {const char*} 服务器监听地址，格式：ip:port
	 * @param count {int} 连接池的大小限制
	 * @param idx {size_t} 该连接池对象在集合中的下标位置(从 0 开始)
	 */
	virtual acl::connect_pool* create_pool(const char* addr,
		int count, size_t idx);
private:
	int   conn_timeout_;
	int   rw_timeout_;
};

} // namespace acl
