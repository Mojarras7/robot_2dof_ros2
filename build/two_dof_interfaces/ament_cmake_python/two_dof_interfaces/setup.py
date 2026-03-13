from setuptools import find_packages
from setuptools import setup

setup(
    name='two_dof_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('two_dof_interfaces', 'two_dof_interfaces.*')),
)
