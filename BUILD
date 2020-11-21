package(
    default_visibility = ["//visibility:public"],
)

load("@rules_cc//cc:defs.bzl", "cc_binary")
load("@envoy//bazel:envoy_build_system.bzl", "envoy_cc_binary")

licenses(["notice"])  # Apache 2

cc_binary(
    name = "mod_pagespeed",
    deps = [
        "//net/instaweb:net_instaweb_lib",
        "//net/instaweb/rewriter:html_minifier_main_lib",
    ],
)

cc_binary(
    name = "libmod_pagespeed.so",
    linkshared = 1,
    linkstatic = 0,
    visibility = ["//visibility:public"],
    deps = ["//pagespeed/apache"],
)

alias(
    name = "fetcher",
    actual = "//pagespeed/envoy:envoy_fetcher",
)

alias(
    name = "http_filter_config",
    actual = "//pagespeed/envoy:http_filter_config",
)

alias(
    name = "main",
    actual = "@envoy//source/exe:envoy_main_entry_lib",
)


envoy_cc_binary(
    name = "envoy",
    repository = "@envoy",
    deps = [
        ":fetcher",
        ":http_filter_config",
        ":main",
    ],
)

