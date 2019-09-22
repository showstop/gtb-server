#ifndef __PROCESS_UTIL__
#define __PROCESS_UTIL__

#include <ServerBase/sb_define.h>

struct execute_result
{
	unsigned int exit_code;
	std::string std_out;
	std::string std_err;

	execute_result(void)
		: exit_code(0)
	{}
};

#if defined(_WIN32) || defined(_WIN64)
class cpipe
{
private:
	HANDLE read_;
	HANDLE write_;

public:
	cpipe(unsigned int buff_size)
		: read_(NULL), write_(NULL)
	{
		SECURITY_ATTRIBUTES sa;
		memset(&sa, 0, sizeof(sa));
		sa.bInheritHandle = TRUE;
		if (CreatePipe(&read_, &write_, &sa, buff_size) == FALSE)
		{
			throw std::exception();
		}
	}
	~cpipe(void)
	{
		CloseHandle(read_);
		read_ = NULL;

		CloseHandle(write_);
		write_ = NULL;
	}

	HANDLE get_read_handle(void) const
	{
		return read_;
	}

	HANDLE get_write_handle(void) const
	{
		return write_;
	}

	unsigned int get_size(void) const
	{
		return GetFileSize(read_, NULL);
	}

	bool read(char *buffer, unsigned int size, unsigned int *bytes_read)
	{
		bool result = false;

		DWORD bytes = 0;
		if (ReadFile(read_, buffer, size, &bytes, NULL) == TRUE)
		{
			result = true;
		}
		else
		{
			result = false;
		}

		if (bytes_read != NULL)
		{
			*bytes_read = bytes;
		}

		return result;
	}

	bool write(const char *buffer, unsigned int size, unsigned int *bytes_written)
	{
		bool result = false;

		DWORD bytes = 0;
		if (WriteFile(write_, buffer, size, &bytes, NULL) == TRUE)
		{
			result = true;
		}
		else
		{
			result = false;
		}

		if (bytes_written != NULL)
		{
			*bytes_written = bytes;
		}

		return result;
	}
};
#else

#include <fcntl.h>
#include <unistd.h>

class cpipe
{
private:
	int fd_[2];

public:
	cpipe(unsigned int buff_size = 0)
	{
		(void)buff_size;	// no meaning in linux

		if (pipe(fd_) == -1)
		{
			printf("[Pipe::Pipe()] CreatePipe() failed. %d:%s\n", errno, strerror(errno));
			throw std::exception();
		}
		if (fcntl(fd_[0], F_SETFL, O_NONBLOCK) == -1)
		{
			printf("[Pipe::Pipe()] fcntl failed. %d:%s\n", errno, strerror(errno));
			throw std::exception();
		}

	}
	~cpipe(void)
	{
	}

	int get_read_handle(void) const
	{
		return fd_[0];
	}

	int get_write_handle(void) const
	{
		return fd_[1];
	}

	bool read(char *buffer, unsigned int size, unsigned int *bytes_read)
	{
		bool result = false;

		unsigned int bytes = 0;
		if ((bytes = ::read(fd_[0], buffer, size)) > 0)
		{
			result = true;
		}
		else
		{
			result = false;
		}

		if (bytes_read != NULL)
		{
			*bytes_read = bytes;
		}

		return result;
	}
};
#endif

bool kill_process(unsigned int pid);
bool execute(const std::string &command, unsigned int *pid);

#endif