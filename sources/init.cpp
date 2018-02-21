#pragma once

#ifdef _WIN32
# include "stdafx.h"
#elif __APPLE__
# include "../includes/stdafx.h"
#endif

namespace init
{
	static t_tick_data		*tick_data(void)
	{
		t_tick_data	*data;
		data = (t_tick_data *)malloc(sizeof(t_tick_data));
		data->epoch = new std::deque<size_t>(0);
		data->px = new std::deque<float>(0);
		data->vol = new std::deque<float>(0);
		return (data);
	}
	static t_ohlc_data		*ohlc_data(void)
	{
		t_ohlc_data	*data;
		data = (t_ohlc_data *)malloc(sizeof(t_ohlc_data));
		return (data);
	}
	static t_account	*account(void)
	{
		t_account	*acc;
		//PARSE THAT PARAMS BRO
		acc = (t_account *)malloc(sizeof(t_account));
		return (acc);
	}
	static t_ticker	*ticker(void)
	{
		t_ticker	*ticker;
		ticker = (t_ticker *)malloc(sizeof(t_ticker));
		return (ticker);
	}
	static t_risk		*risk(void)
	{
		t_risk	*rsk;
		rsk = (t_risk *)malloc(sizeof(t_risk));
		return (rsk);
	}
	t_env		*env(void)
	{
		t_env	*env;
		env = (t_env *)malloc(sizeof(t_env));
		t_risk				*rsk;
		t_ticker			*ticker;
		t_account			*acc;
		t_tick_data			*data;

		env->rsk =				init::risk();
		env->acc =				init::account();
		env->data =				init::tick_data();
		env->ticker =			init::ticker();
		env->order_book =		new std::deque<t_open_order>(0);
		env->order_history =	new std::deque<t_closed_order>(0);
		NB_LONG = 0;
		NB_SHORT = 0;
		//param_parse("...");
		//t_tick_data *data = static_cast<t_tick_data*>(histo); //shall result depend on parameters parsing
		return (env);
	}
}