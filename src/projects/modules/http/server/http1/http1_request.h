//==============================================================================
//
//  OvenMediaEngine
//
//  Created by Getroot
//  Copyright (c) 2022 AirenSoft. All rights reserved.
//
//==============================================================================

#pragma once

#include "../http_request.h"

namespace http
{
	namespace svr
	{
		namespace h1
		{
			class Http1Request : public HttpRequest
			{
			public:
				// Constructor
				Http1Request(const std::shared_ptr<ov::ClientSocket> &client_socket);

				size_t GetContentLength() const noexcept;

				/////////////////////////////////////
				// Implementation of HttpRequest
				/////////////////////////////////////

				ssize_t AppendHeaderData(const std::shared_ptr<const ov::Data> &data) override;
				StatusCode GetHeaderParingStatus() const override;
				Method GetMethod() const noexcept;
				ov::String GetHttpVersion() const noexcept override;
				double GetHttpVersionAsNumber() const noexcept override;
				// Path of the URI (including query strings & excluding domain and port)
				// Example: /<app>/<stream>/...?a=b&c=d
				const ov::String &GetRequestTarget() const noexcept override;
				ov::String GetHeader(const ov::String &key) const noexcept override;
				const bool IsHeaderExists(const ov::String &key) const noexcept override;

			private:
				prot::h1::HttpRequestHeaderParser _http_header_parser;
			};
		} // namespace h1
	} // namespace svr
}  // namespace http