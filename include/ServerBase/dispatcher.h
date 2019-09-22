#ifndef __K_SB_DISPATCHER__
#define __K_SB_DISPATCHER__

namespace protocol {

	template<typename IdentifierT, typename FunctorT>
	class dispatcher
	{
	private:
		typedef std::map<IdentifierT, FunctorT> functor_map_t;

	private:
		functor_map_t functors_;

	public:
		bool add(IdentifierT id, const FunctorT &functor)
		{
			if (functors_.insert(std::make_pair(id, functor)).second == false)
			{
				assert(!"[dispatcher::add()] duplicated id.");
				return false;
			}

			return true;
		}

		bool remove(IdentifierT id)
		{
			typename functor_map_t::iterator it = functors_.find(id);
			if (it == functors_.end())
			{
				return false;
			}

			functors_.erase(it);

			return true;
		}

		void clear()
		{
			functors_.clear();
		}

		bool dispatch(IdentifierT id) const
		{
			FunctorT functor;
			if (find(id, functor) == true)
			{
				functor();
				return true;
			}

			return false;
		}
		template<typename Arg1T>
		bool dispatch(IdentifierT id, Arg1T arg1, void* context) const
		{
			FunctorT functor;
			if (find(id, functor) == true)
			{
				functor(arg1, context);
				return true;
			}

			return false;
		}
		template<typename Arg1T, typename Arg2T>
		bool dispatch(IdentifierT id, Arg1T arg1, Arg2T arg2, void* context) const
		{
			FunctorT functor;
			if (find(id, functor) == true)
			{
				functor(arg1, arg2, context);
				return true;
			}

			return false;
		}
		template<typename Arg1T, typename Arg2T, typename Arg3T>
		bool dispatch(IdentifierT id, Arg1T arg1, Arg2T arg2, Arg3T arg3, void* context) const
		{
			FunctorT functor;
			if (find(id, functor) == true)
			{
				functor(arg1, arg2, arg3, context);
				return true;
			}

			return false;
		}
		template<typename Arg1T, typename Arg2T, typename Arg3T, typename Arg4T>
		bool dispatch(IdentifierT id, Arg1T arg1, Arg2T arg2, Arg3T arg3, Arg4T arg4, void* context) const
		{
			FunctorT functor;
			if (find(id, functor) == true)
			{
				functor(arg1, arg2, arg3, arg4, context);
				return true;
			}

			return false;
		}

	private:
		bool find(IdentifierT id, FunctorT &item) const
		{
			typename functor_map_t::const_iterator it = functors_.find(id);
			if (it == functors_.end())
			{
				return false;
			}

			item = (*it).second;

			return true;
		}
	};

}


#endif