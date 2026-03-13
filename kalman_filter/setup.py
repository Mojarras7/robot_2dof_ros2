from setuptools import find_packages, setup
from glob import glob

package_name = 'kalman_filter'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages', ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name + '/launch', glob('launch/*.launch.py')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='mojarras',
    maintainer_email='mojarrasalejandro@gmail.com',
    description='2-state Kalman filter for joint states + rosbag plotting tools',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'kalman_filter_node = kalman_filter.kalman_filter_node:main',
            'plot_kalman_rosbag = kalman_filter.plot_kalman_rosbag:main',
        ],
    },
)
