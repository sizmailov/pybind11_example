import pytest


def test_load_module():
    import example_module


def test_add():
    from example_module import add
    assert add(1.0, 2.0) == 3.0
