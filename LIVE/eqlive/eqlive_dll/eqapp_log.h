#pragma once

std::shared_ptr<spdlog::logger> g_Log;

std::string g_LogFileName = fmt::format("{}/log.txt", g_EQAppName);

void EQAPP_Log_Load()
{
    //auto consoleSink = std::make_shared<spdlog::sinks::stdout_sink_mt>();
    //consoleSink->set_level(spdlog::level::trace);
    //consoleSink->set_pattern("[%^%l%$] %v");

    auto fileSink = std::make_shared<spdlog::sinks::basic_file_sink_mt>(g_LogFileName, true);
    fileSink->set_level(spdlog::level::trace);

    g_Log = std::make_shared<spdlog::logger>("root", spdlog::sinks_init_list({fileSink}));
    g_Log->set_level(spdlog::level::trace);
    g_Log->flush_on(spdlog::level::trace);
    g_Log->set_pattern("[%c] [%s:%#:%!()] %v");

    spdlog::set_level(spdlog::level::trace);
    spdlog::flush_on(spdlog::level::trace);

    spdlog::set_default_logger(g_Log);
}
